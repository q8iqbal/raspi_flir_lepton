#!/usr/bin/env python

import re
import os
import subprocess
import sys

from setuptools import setup, find_packages, Command
from setuptools.command.sdist import sdist
from distutils.command.build_ext import build_ext

from glob import glob

cmdclass = {}

try:
    from pyqt_distutils.build_ui import build_ui
    has_build_ui = True
except ImportError:
    has_build_ui = False

# if you need to build docs folder
# try:
#     from sphinx.setup_command import BuildDoc
#     cmdclass["build_docs"] = BuildDoc
# except ImportError:
#     pass


with open("app/__init__.py") as f:
    _version = re.search(r"__version__\s+=\s+\'(.*)\'", f.read()).group(1)


if has_build_ui:
    class build_res(build_ui):
        """Build UI, resources and translations."""

        def run(self):
            # you need app.pro to use commented command
            # # build translations
            # check_call(["pyside2-lupdate", "app.pro"])

            # lrelease = os.environ.get("LRELEASE_BIN")
            # if not lrelease:
            #     lrelease = "lrelease"

            # check_call([lrelease, "app.pro"])

            # build UI & resources
            build_ui.run(self)

    cmdclass["build_res"] = build_res


class custom_sdist(sdist):
    """Custom sdist command."""

    def run(self):
        self.run_command("build_res")
        sdist.run(self)


cmdclass["sdist"] = custom_sdist


class run_app(sdist):
    def run(self):
        os.system("python -m app")

cmdclass["run_app"] = run_app



class bdist_app(Command):
    """Custom command to build the application. """

    description = "Build the application"
    user_options = []

    def initialize_options(self):
        pass

    def finalize_options(self):
        pass

    def run(self):
        self.run_command("build_res")
        subprocess.check_call(["pyinstaller", "-y", "app.spec"])


cmdclass["bdist_app"] = bdist_app

class CMakeBuild(build_ext):

    

    def run(self):
        try:
            out = subprocess.check_output(['cmake', '--version'])
        except OSError:
            raise RuntimeError(
                "CMake must be installed to build the following extensions: " +
                ", ".join(e.name for e in self.extensions))

        self.build_temp = "./lepton/wrapper"
        self.extensions = ["cpp"]

        build_directory = os.path.abspath(self.build_temp)

        cmake_args = [
            '-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=' + build_directory,
            '-DPYTHON_EXECUTABLE=' + sys.executable
        ]

        cfg = 'Debug' if self.debug else 'Release'
        build_args = ['--config', cfg]

        cmake_args += ['-DCMAKE_BUILD_TYPE=' + cfg]

        # Assuming Makefiles
        build_args += ['--', '-j2']

        self.build_args = build_args

        env = os.environ.copy()
        env['CXXFLAGS'] = '{} -DVERSION_INFO=\\"{}\\"'.format(
            env.get('CXXFLAGS', ''),
            self.distribution.get_version())
        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)

        # CMakeLists.txt is in the same directory as this setup.py file
        # cmake_list_dir = os.path.abspath(os.path.dirname(__file__))
        cmake_list_dir = build_directory
        print('-'*10, 'Running CMake prepare', '-'*40)
        subprocess.check_call(['cmake', cmake_list_dir] + cmake_args,
                              cwd=self.build_temp, env=env)

        print('-'*10, 'Building extensions', '-'*40)
        cmake_cmd = ['cmake', '--build', '.'] + self.build_args
        subprocess.check_call(cmake_cmd,
                              cwd=self.build_temp)

cmdclass["build_sdk"] = CMakeBuild



CURDIR = os.path.dirname(os.path.abspath(__file__))
with open(os.path.join(CURDIR, "requirements.txt")) as requirements:
    REQUIREMENTS = requirements.read().splitlines()


setup(
    name="Lepton Raspberry Pi",
    version=_version,
    packages=find_packages(),
    description="Program to meassure temperature and show live video from lepton 2.5",
    author="iqbal nur imansyah",
    author_email="iqbalnurimansyah@it.student.pens.ac.id",
    license="MIT",
    entry_points={"gui_scripts": ["app=app.__main__:main"]},
    install_requires=REQUIREMENTS,
    cmdclass=cmdclass,
)
