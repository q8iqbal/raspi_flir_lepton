#include <pybind11/pybind11.h>

#include "../sdk/LEPTON_SDKConfig.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_sdk_config, handle){
    handle.doc() = "typedefs for coding style/conventions ";

    handle.attr("USE_DEPRECATED_SERIAL_NUMBER_INTERFACE") = py::int_(USE_DEPRECATED_SERIAL_NUMBER_INTERFACE);
    handle.attr("USE_DEPRECATED_PART_NUMBER_INTERFACE") = py::int_(USE_DEPRECATED_PART_NUMBER_INTERFACE);
    handle.attr("USE_DEPRECATED_ASICID_INTERFACE") = py::int_(USE_DEPRECATED_ASICID_INTERFACE);
    handle.attr("USE_DEPRECATED_HOUSING_TCP_INTERFACE") = py::int_(USE_DEPRECATED_HOUSING_TCP_INTERFACE);
}