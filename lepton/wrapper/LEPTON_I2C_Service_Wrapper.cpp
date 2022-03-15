#include <pybind11/pybind11.h>

#include "../sdk/LEPTON_I2C_Service.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_i2c_service, handle){
    handle.doc() = "Lepton I2C Device Driver Service Layer Interface";

    handle.def("LEP_I2C_MasterOpen", &LEP_I2C_MasterOpen);
    handle.def("LEP_I2C_MasterClose", &LEP_I2C_MasterClose);
    handle.def("LEP_I2C_MasterReset", &LEP_I2C_MasterReset);
    handle.def("LEP_I2C_MasterReadData", &LEP_I2C_MasterReadData);
    handle.def("LEP_I2C_MasterWriteData", &LEP_I2C_MasterWriteData);
    handle.def("LEP_I2C_MasterReadRegister", &LEP_I2C_MasterReadRegister);
    handle.def("LEP_I2C_MasterWriteRegister", &LEP_I2C_MasterWriteRegister);
    handle.def("LEP_I2C_MasterStatus", &LEP_I2C_MasterStatus);
}