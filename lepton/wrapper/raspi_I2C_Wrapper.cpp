#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

#include "../sdk/raspi_I2C.h"

PYBIND11_MODULE(raspi_i2c, handle){
    handle.def("DEV_I2C_MasterInit",&DEV_I2C_MasterInit);
    handle.def("DEV_I2C_MasterClose",&DEV_I2C_MasterClose);
    handle.def("DEV_I2C_MasterReset",&DEV_I2C_MasterReset);
    handle.def("DEV_I2C_MasterReadData",&DEV_I2C_MasterReadData);
    handle.def("DEV_I2C_MasterWriteData",&DEV_I2C_MasterWriteData);
    handle.def("DEV_I2C_MasterReadRegister",&DEV_I2C_MasterReadRegister);
    handle.def("DEV_I2C_MasterWriteRegister",&DEV_I2C_MasterWriteRegister);
    handle.def("DEV_I2C_MasterStatus",&DEV_I2C_MasterStatus);
}