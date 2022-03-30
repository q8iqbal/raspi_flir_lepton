#include <pybind11/pybind11.h>

#include "../sdk/LEPTON_I2C_Protocol.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_i2c_protocol, handle){
    handle.doc() = "Lepton I2C Protocol Layer ";
    
    handle.attr("LEPTON_I2C_COMMAND_BUSY_WAIT_COUNT") = py::int_(LEPTON_I2C_COMMAND_BUSY_WAIT_COUNT);

    py::enum_<LEP_I2C_COMMAND_STATUS_TAG>(handle,"LEP_I2C_COMMAND_STATUS_TAG")
        .value("LEP_I2C_COMMAND_NOT_BUSY",LEP_I2C_COMMAND_STATUS_TAG::LEP_I2C_COMMAND_NOT_BUSY)
        .value("LEP_I2C_COMMAND_IS_BUSY",LEP_I2C_COMMAND_STATUS_TAG::LEP_I2C_COMMAND_IS_BUSY)
        .value("LEP_I2C_END_COMMAND_STATUS",LEP_I2C_COMMAND_STATUS_TAG::LEP_I2C_END_COMMAND_STATUS)
        .export_values();
    
    handle.def("LEP_I2C_GetCommandBusyStatus", &LEP_I2C_GetCommandBusyStatus);
    handle.def("LEP_I2C_SetCommandRegister", &LEP_I2C_SetCommandRegister);
    handle.def("LEP_I2C_OpenPort", &LEP_I2C_OpenPort);
    handle.def("LEP_I2C_ClosePort", &LEP_I2C_ClosePort);
    handle.def("LEP_I2C_ResetPort", &LEP_I2C_ResetPort);
    handle.def("LEP_I2C_GetAttribute", &LEP_I2C_GetAttribute);
    handle.def("LEP_I2C_SetAttribute", &LEP_I2C_SetAttribute);
    handle.def("LEP_I2C_RunCommand", &LEP_I2C_RunCommand);
    handle.def("LEP_I2C_ReadData", &LEP_I2C_ReadData);
    handle.def("LEP_I2C_WriteData", &LEP_I2C_WriteData);
    handle.def("LEP_I2C_GetPortStatus", &LEP_I2C_GetPortStatus);
    handle.def("LEP_I2C_GetDeviceAddress", &LEP_I2C_GetDeviceAddress);
    handle.def("LEP_I2C_DirectWriteRegister", &LEP_I2C_DirectWriteRegister);
    handle.def("LEP_I2C_DirectWriteBuffer", &LEP_I2C_DirectWriteBuffer);
    handle.def("LEP_I2C_DirectReadRegister", &LEP_I2C_DirectReadRegister);
}