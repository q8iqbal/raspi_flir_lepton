#include "iostream"
#include <pybind11/pybind11.h>

#include "../sdk/crc16.h"

namespace py = pybind11;


PYBIND11_MODULE(crc16, handle){
    handle.doc() = "Cyclic Redundancy Check 16 functions";
    handle.def("byte_crc16", &ByteCRC16);
    handle.def("calc_crc16_words", &CalcCRC16Words);
    handle.def("calc_crc16_bytes", &CalcCRC16Bytes);
}