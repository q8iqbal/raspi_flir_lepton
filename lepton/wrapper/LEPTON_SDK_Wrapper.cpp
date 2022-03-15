#include <pybind11/pybind11.h>

#include "../sdk/LEPTON_SDK.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_sdk, handle){
    handle.attr("LEP_SDK_VERSION_MAJOR") = py::int_(LEP_SDK_VERSION_MAJOR);
    handle.attr("LEP_SDK_VERSION_MINOR") = py::int_(LEP_SDK_VERSION_MINOR);
    handle.attr("LEP_SDK_VERSION_BUILD") = py::int_(LEP_SDK_VERSION_BUILD);
    handle.attr("LEP_SDK_MODULE_BASE") = py::int_(LEP_SDK_MODULE_BASE);
    handle.attr("LEP_SDK_ENABLE_STATE") = py::int_(LEP_SDK_ENABLE_STATE);

    py::class_<LEP_SDK_VERSION_T>(handle,"LEP_SDK_VERSION_T")
        .def(py::init<>())
        .def_readwrite("major",&LEP_SDK_VERSION_T::major)
        .def_readwrite("minor",&LEP_SDK_VERSION_T::minor)
        .def_readwrite("build",&LEP_SDK_VERSION_T::build)
        .def_readwrite("reserved",&LEP_SDK_VERSION_T::reserved);
    
    py::enum_<LEP_SDK_BOOT_STATUS_E>(handle,"LEP_SDK_BOOT_STATUS_E")
        .value("LEP_BOOT_STATUS_NOT_BOOTED",LEP_SDK_BOOT_STATUS_E::LEP_BOOT_STATUS_NOT_BOOTED)
        .value("LEP_BOOT_STATUS_BOOTED",LEP_SDK_BOOT_STATUS_E::LEP_BOOT_STATUS_BOOTED)
        .value("LEP_END_BOOT_STATUS",LEP_SDK_BOOT_STATUS_E::LEP_END_BOOT_STATUS)
        .export_values();

    handle.def("LEP_OpenPort",&LEP_OpenPort);
    handle.def("LEP_ClosePort",&LEP_ClosePort);
    handle.def("LEP_ResetPort",&LEP_ResetPort);
    handle.def("LEP_GetPortStatus",&LEP_GetPortStatus);
    handle.def("LEP_GetDeviceAddress",&LEP_GetDeviceAddress);
    handle.def("LEP_GetAttribute",&LEP_GetAttribute);
    handle.def("LEP_SetAttribute",&LEP_SetAttribute);
    handle.def("LEP_RunCommand",&LEP_RunCommand);
    handle.def("LEP_DirectWriteBuffer",&LEP_DirectWriteBuffer);
    handle.def("LEP_DirectWriteRegister",&LEP_DirectWriteRegister);
    handle.def("LEP_DirectReadRegister",&LEP_DirectReadRegister);
    handle.def("LEP_GetSDKVersion",&LEP_GetSDKVersion);
    handle.def("LEP_GetCameraBootStatus",&LEP_GetCameraBootStatus);
}