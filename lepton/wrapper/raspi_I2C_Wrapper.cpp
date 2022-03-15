#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

#include "../sdk/raspi_I2C.h"
#include "../sdk/LEPTON_ErrorCodes.h"
#include "../sdk/LEPTON_Types.h"

PYBIND11_MODULE(raspi_i2c, handle){
}