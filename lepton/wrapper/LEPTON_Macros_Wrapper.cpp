#include <pybind11/pybind11.h>

#include "../sdk/LEPTON_Macros.h"
#include "../sdk/LEPTON_Types.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_macros, handle){
    handle.doc() = "USEFUL MACROS";

    handle.def("low_word", [](uint16_t longVariable){
        return LOW_WORD(longVariable);
    });

    handle.def("high_word", [](uint16_t longVariable){
        return HIGH_WORD(longVariable);
    });

    handle.def("low_byte", [](uint8_t w){
        return LOW_BYTE(w);
    });

    handle.def("high_byte", [](uint8_t w){
        return HIGH_BYTE(w);
    });

    handle.def("low_nibble", [](uint8_t w){
        return LOW_NIBBLE(w);
    });

    handle.def("high_nibble", [](uint8_t w){
        return HIGH_NIBBLE(w);
    });

    handle.def("clr_bit", [](auto _port, auto _bit){
        return CLR_BIT(_port,_bit);
    });

    handle.def("reverse_endieness_uint16", [](uint16_t var){
        return REVERSE_ENDIENESS_UINT16(var);
    });
    
    handle.def("reverse_endieness_uint32", [](uint32_t var){
        return REVERSE_ENDIENESS_UINT32(var);
    });

    handle.def("reverse_nibble_uint8", [](uint8_t var){
        return REVERSE_NIBBLE_UINT8(var);
    });

    handle.def("reverse_byteorder_uint32", [](uint32_t var){
        return REVERSE_BYTEORDER_UINT32(var);
    });

    handle.def("word_swap_16", [](uint32_t var){
        return WORD_SWAP_16(var);
    });
}