#include <pybind11/pybind11.h>

#include "../sdk/LEPTON_I2C_Reg.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_i2c_reg, handle){
    handle.doc() = "Defines the Lepton I2C Interface for Host Command and Control";

    handle.attr("LEP_I2C_DEVICE_ADDRESS") = py::int_(LEP_I2C_DEVICE_ADDRESS);

    handle.attr("LEP_DATA_BUFFER_0_BASE_ADDR") = py::int_(LEP_DATA_BUFFER_0_BASE_ADDR);
    handle.attr("LEP_DATA_BUFFER_1_BASE_ADDR") = py::int_(LEP_DATA_BUFFER_1_BASE_ADDR);

    handle.attr("LEP_I2C_REG_BASE_ADDR") = py::int_(LEP_I2C_REG_BASE_ADDR);

    handle.attr("LEP_I2C_POWER_REG") = py::int_(LEP_I2C_POWER_REG);

    handle.attr("LEP_I2C_STATUS_REG") = py::int_(LEP_I2C_STATUS_REG);
    handle.attr("LEP_I2C_COMMAND_REG") = py::int_(LEP_I2C_COMMAND_REG);
    handle.attr("LEP_I2C_DATA_LENGTH_REG") = py::int_(LEP_I2C_DATA_LENGTH_REG);
    handle.attr("LEP_I2C_DATA_0_REG") = py::int_(LEP_I2C_DATA_0_REG);
    handle.attr("LEP_I2C_DATA_1_REG") = py::int_(LEP_I2C_DATA_1_REG);
    handle.attr("LEP_I2C_DATA_2_REG") = py::int_(LEP_I2C_DATA_2_REG);
    handle.attr("LEP_I2C_DATA_3_REG") = py::int_(LEP_I2C_DATA_3_REG);
    handle.attr("LEP_I2C_DATA_4_REG") = py::int_(LEP_I2C_DATA_4_REG);
    handle.attr("LEP_I2C_DATA_5_REG") = py::int_(LEP_I2C_DATA_5_REG);
    handle.attr("LEP_I2C_DATA_6_REG") = py::int_(LEP_I2C_DATA_6_REG);
    handle.attr("LEP_I2C_DATA_7_REG") = py::int_(LEP_I2C_DATA_7_REG);
    handle.attr("LEP_I2C_DATA_8_REG") = py::int_(LEP_I2C_DATA_8_REG);
    handle.attr("LEP_I2C_DATA_9_REG") = py::int_(LEP_I2C_DATA_9_REG);
    handle.attr("LEP_I2C_DATA_10_REG") = py::int_(LEP_I2C_DATA_10_REG);
    handle.attr("LEP_I2C_DATA_11_REG") = py::int_(LEP_I2C_DATA_11_REG);
    handle.attr("LEP_I2C_DATA_12_REG") = py::int_(LEP_I2C_DATA_12_REG);
    handle.attr("LEP_I2C_DATA_13_REG") = py::int_(LEP_I2C_DATA_13_REG);
    handle.attr("LEP_I2C_DATA_14_REG") = py::int_(LEP_I2C_DATA_14_REG);
    handle.attr("LEP_I2C_DATA_15_REG") = py::int_(LEP_I2C_DATA_15_REG);

    handle.attr("LEP_I2C_DATA_CRC_REG") = py::int_(LEP_I2C_DATA_CRC_REG);

    handle.attr("LEP_I2C_DATA_BUFFER_0") = py::int_(LEP_I2C_DATA_BUFFER_0);
    handle.attr("LEP_I2C_DATA_BUFFER_0_END") = py::int_(LEP_I2C_DATA_BUFFER_0_END);
    handle.attr("LEP_I2C_DATA_BUFFER_0_LENGTH") = py::int_(LEP_I2C_DATA_BUFFER_0_LENGTH);

    handle.attr("LEP_I2C_DATA_BUFFER_1") = py::int_(LEP_I2C_DATA_BUFFER_1);
    handle.attr("LEP_I2C_DATA_BUFFER_1_END") = py::int_(LEP_I2C_DATA_BUFFER_1_END);
    handle.attr("LEP_I2C_DATA_BUFFER_1_LENGTH") = py::int_(LEP_I2C_DATA_BUFFER_1_LENGTH);

    handle.attr("LEP_I2C_STATUS_BUSY_BIT_MASK") = py::int_(LEP_I2C_STATUS_BUSY_BIT_MASK);


}