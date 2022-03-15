#include <pybind11/pybind11.h>

#include "../sdk/LEPTON_AGC.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_agc, handle){
    handle.attr("LEP_AGC_MODULE_BASE") = py::int_(LEP_AGC_MODULE_BASE);
}