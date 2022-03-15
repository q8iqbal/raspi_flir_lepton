#include <pybind11/pybind11.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include "../sdk/LEPTON_Types.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_type, handle){
    handle.doc() = "typedefs for coding style/conventions for lepton sdk";
    handle.attr("LEP_FAILURE") = py::int_(LEP_FAILURE);
    handle.attr("LEP_SUCCESS") = py::int_(LEP_SUCCESS);
    handle.attr("LEP_TRUE") = py::int_(LEP_TRUE);
    handle.attr("LEP_FALSE") = py::int_(LEP_FALSE);
    handle.attr("LEP_NULL") = py::int_(LEP_NULL);

    handle.attr("LEP_GET_TYPE") = py::int_(LEP_GET_TYPE);
    handle.attr("LEP_SET_TYPE") = py::int_(LEP_SET_TYPE);
    handle.attr("LEP_RUN_TYPE") = py::int_(LEP_RUN_TYPE);

    py::enum_<LEP_BYTE_ORDER_T>(handle,"LEP_BYTE_ORDER_T")
        .value("LEP_LSB_FIRST", LEP_BYTE_ORDER_T::LEP_LSB_FIRST)
        .value("LEP_MSB_FIRST", LEP_BYTE_ORDER_T::LEP_MSB_FIRST)
        .export_values();

    py::enum_<LEP_OPERATION_STATE>(handle,"LEP_OPERATION_STATE")
        .value("LEP_READY", LEP_OPERATION_STATE::LEP_READY)
        .value("LEP_BUSY", LEP_OPERATION_STATE::LEP_BUSY)
        .value("LEP_WAITING", LEP_OPERATION_STATE::LEP_WAITING)
        .export_values();

    py::enum_<LEP_ENABLE_STATE>(handle,"LEP_ENABLE_STATE")
        .value("LEP_DISABLED",LEP_ENABLE_STATE::LEP_DISABLED)
        .value("LEP_ENABLED",LEP_ENABLE_STATE::LEP_ENABLED)
        .export_values();

    py::enum_<LEP_ON_STATE>(handle,"LEP_ON_STATE")
        .value("LEP_OFF",LEP_ON_STATE::LEP_OFF)
        .value("LEP_ON",LEP_ON_STATE::LEP_ON)
        .export_values();

    py::enum_<LEP_CAMERA_PORT_E>(handle,"LEP_CAMERA_PORT_E_TAG")
        .value("LEP_CCI_TWI",LEP_CAMERA_PORT_E::LEP_CCI_TWI)
        .value("LEP_CCI_SPI",LEP_CAMERA_PORT_E::LEP_CCI_SPI)
        .value("LEP_END_CCI_PORTS",LEP_CAMERA_PORT_E::LEP_END_CCI_PORTS)
        .export_values();
    
    py::enum_<LEP_TWI_CLOCK_RATE_T>(handle,"LEP_TWI_CLOCK_RATE_T_TAG")
        .value("LEP_TWI_CLOCK_100KHZ",LEP_TWI_CLOCK_RATE_T::LEP_TWI_CLOCK_100KHZ)
        .value("LEP_TWI_CLOCK_400KHZ",LEP_TWI_CLOCK_RATE_T::LEP_TWI_CLOCK_400KHZ)
        .value("LEP_TWI_CLOCK_1MHZ",LEP_TWI_CLOCK_RATE_T::LEP_TWI_CLOCK_1MHZ)
        .value("LEP_END_TWI_CLOCK_RATE",LEP_TWI_CLOCK_RATE_T::LEP_END_TWI_CLOCK_RATE)
        .export_values();

    py::enum_<LEP_SPI_CLOCK_RATE_T>(handle,"LEP_SPI_CLOCK_RATE_T_TAG")
        .value("LEP_SPI_CLOCK_2MHZ",LEP_SPI_CLOCK_RATE_T_TAG::LEP_SPI_CLOCK_2MHZ)
        .value("LEP_SPI_CLOCK_10MHZ",LEP_SPI_CLOCK_RATE_T_TAG::LEP_SPI_CLOCK_10MHZ)
        .value("LEP_SPI_CLOCK_20MHZ",LEP_SPI_CLOCK_RATE_T_TAG::LEP_SPI_CLOCK_20MHZ)
        .value("LEP_END_SPI_CLOCK_RATE",LEP_SPI_CLOCK_RATE_T_TAG::LEP_END_SPI_CLOCK_RATE)
        .export_values();

    py::class_<LEP_CAMERA_PORT_DESC_T>(handle,"LEP_CAMERA_PORT_DESC_T")
        .def(py::init<>())
        .def_readwrite("portID",&LEP_CAMERA_PORT_DESC_T::portID)
        .def_readwrite("portType",&LEP_CAMERA_PORT_DESC_T::portType)
        .def_readwrite("portBaudRate",&LEP_CAMERA_PORT_DESC_T::portBaudRate)
        .def_readwrite("deviceAddress",&LEP_CAMERA_PORT_DESC_T::deviceAddress);
}