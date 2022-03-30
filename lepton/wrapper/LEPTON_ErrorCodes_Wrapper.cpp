#include <pybind11/pybind11.h>

#include "../sdk/LEPTON_ErrorCodes.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_error_codes, handle){
    handle.doc() = "Contains the Lepton SDK Error Codes";

    py::enum_<Result>(handle,"Result")
        .value("LEP_OK",Result::LEP_OK)
        .value("LEP_COMM_OK",Result::LEP_COMM_OK)
        .value("LEP_ERROR",Result::LEP_ERROR)
        .value("LEP_NOT_READY",Result::LEP_NOT_READY)
        .value("LEP_RANGE_ERROR",Result::LEP_RANGE_ERROR)
        .value("LEP_CHECKSUM_ERROR",Result::LEP_CHECKSUM_ERROR)
        .value("LEP_BAD_ARG_POINTER_ERROR",Result::LEP_BAD_ARG_POINTER_ERROR)
        .value("LEP_DATA_SIZE_ERROR",Result::LEP_DATA_SIZE_ERROR)
        .value("LEP_UNDEFINED_FUNCTION_ERROR",Result::LEP_UNDEFINED_FUNCTION_ERROR)
        .value("LEP_FUNCTION_NOT_SUPPORTED",Result::LEP_FUNCTION_NOT_SUPPORTED)
        .value("LEP_OTP_WRITE_ERROR",Result::LEP_OTP_WRITE_ERROR)
        .value("LEP_OTP_READ_ERROR",Result::LEP_OTP_READ_ERROR)
        .value("LEP_OTP_NOT_PROGRAMMED_ERROR",Result::LEP_OTP_NOT_PROGRAMMED_ERROR)
        .value("LEP_ERROR_I2C_BUS_NOT_READY",Result::LEP_ERROR_I2C_BUS_NOT_READY)
        .value("LEP_ERROR_I2C_BUFFER_OVERFLOW",Result::LEP_ERROR_I2C_BUFFER_OVERFLOW)
        .value("LEP_ERROR_I2C_ARBITRATION_LOST",Result::LEP_ERROR_I2C_ARBITRATION_LOST)
        .value("LEP_ERROR_I2C_BUS_ERROR",Result::LEP_ERROR_I2C_BUS_ERROR)
        .value("LEP_ERROR_I2C_NACK_RECEIVED",Result::LEP_ERROR_I2C_NACK_RECEIVED)
        .value("LEP_ERROR_I2C_FAIL",Result::LEP_ERROR_I2C_FAIL)
        .value("LEP_DIV_ZERO_ERROR",Result::LEP_DIV_ZERO_ERROR)
        .value("LEP_COMM_PORT_NOT_OPEN",Result::LEP_COMM_PORT_NOT_OPEN)
        .value("LEP_COMM_INVALID_PORT_ERROR",Result::LEP_COMM_INVALID_PORT_ERROR)
        .value("LEP_COMM_RANGE_ERROR",Result::LEP_COMM_RANGE_ERROR)
        .value("LEP_ERROR_CREATING_COMM",Result::LEP_ERROR_CREATING_COMM)
        .value("LEP_ERROR_STARTING_COMM",Result::LEP_ERROR_STARTING_COMM)
        .value("LEP_ERROR_CLOSING_COMM",Result::LEP_ERROR_CLOSING_COMM)
        .value("LEP_COMM_CHECKSUM_ERROR",Result::LEP_COMM_CHECKSUM_ERROR)
        .value("LEP_COMM_NO_DEV",Result::LEP_COMM_NO_DEV)
        .value("LEP_TIMEOUT_ERROR",Result::LEP_TIMEOUT_ERROR)
        .value("LEP_COMM_ERROR_WRITING_COMM",Result::LEP_COMM_ERROR_WRITING_COMM)
        .value("LEP_COMM_ERROR_READING_COMM",Result::LEP_COMM_ERROR_READING_COMM)
        .value("LEP_COMM_COUNT_ERROR",Result::LEP_COMM_COUNT_ERROR)
        .value("LEP_OPERATION_CANCELED",Result::LEP_OPERATION_CANCELED)
        .value("LEP_UNDEFINED_ERROR_CODE",Result::LEP_UNDEFINED_ERROR_CODE)
        .export_values();
}