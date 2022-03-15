# set min version of cmake
cmake_minimum_required(VERSION 3.4...3.18)
project(pybind_lepton LANGUAGES C CXX)

# make sure you have pybind11 header in your pc
find_package(pybind11 REQUIRED)

# build sdk .c file to shared object
file(GLOB SOURCES "../sdk/*.c")
add_library(lepton SHARED ${SOURCES})
link_libraries(lepton)

# build c++ wrapper file for python call
pybind11_add_module(crc16 crc16fast_Wrapper.cpp)
pybind11_add_module(lepton_agc LEPTON_AGC_Wrapper.cpp)
pybind11_add_module(lepton_error_codes LEPTON_ErrorCodes_Wrapper.cpp)
pybind11_add_module(lepton_i2c_protocol LEPTON_I2C_Protocol_Wrapper.cpp)
pybind11_add_module(lepton_i2c_reg LEPTON_I2C_Reg_Wrapper.cpp)
pybind11_add_module(lepton_i2c_service LEPTON_I2C_Service_Wrapper.cpp)
pybind11_add_module(lepton_macros LEPTON_Macros_Wrapper.cpp)
pybind11_add_module(lepton_oem LEPTON_OEM_Wrapper.cpp)
pybind11_add_module(lepton_rad LEPTON_RAD_Wrapper.cpp)
pybind11_add_module(lepton_sdk LEPTON_SDK_Wrapper.cpp)
pybind11_add_module(lepton_sdk_config LEPTON_SDKConfig_Wrapper.cpp)
pybind11_add_module(lepton_sys LEPTON_SYS_Wrapper.cpp)
pybind11_add_module(lepton_type LEPTON_Types_Wrapper.cpp)
pybind11_add_module(lepton_vid LEPTON_VID_Wrapper.cpp)
pybind11_add_module(raspi_i2c raspi_I2C_Wrapper.cpp)




