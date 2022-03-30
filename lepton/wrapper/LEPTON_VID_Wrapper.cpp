#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl_bind.h>
#include <pybind11/embed.h>
#include <pybind11/pytypes.h>
#include <pybind11/numpy.h>
#include <array>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h> 
#include <pybind11/chrono.h>

#include "../sdk/LEPTON_VID.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_vid, handle){
    handle.doc() = "Lepton SDK VID (video) Module Command Interface";

    handle.attr("LEP_VID_MODULE_BASE") = py::int_(LEP_VID_MODULE_BASE);
    handle.attr("LEP_CID_VID_POLARITY_SELECT") = py::int_(LEP_CID_VID_POLARITY_SELECT);
    handle.attr("LEP_CID_VID_LUT_SELECT") = py::int_(LEP_CID_VID_LUT_SELECT);
    handle.attr("LEP_CID_VID_LUT_TRANSFER") = py::int_(LEP_CID_VID_LUT_TRANSFER);
    handle.attr("LEP_CID_VID_FOCUS_CALC_ENABLE") = py::int_(LEP_CID_VID_FOCUS_CALC_ENABLE);
    handle.attr("LEP_CID_VID_FOCUS_ROI") = py::int_(LEP_CID_VID_FOCUS_ROI);
    handle.attr("LEP_CID_VID_FOCUS_THRESHOLD") = py::int_(LEP_CID_VID_FOCUS_THRESHOLD);
    handle.attr("LEP_CID_VID_FOCUS_METRIC") = py::int_(LEP_CID_VID_FOCUS_METRIC);
    handle.attr("LEP_CID_VID_SBNUC_ENABLE") = py::int_(LEP_CID_VID_SBNUC_ENABLE);
    handle.attr("LEP_CID_VID_GAMMA_SELECT") = py::int_(LEP_CID_VID_GAMMA_SELECT);
    handle.attr("LEP_CID_VID_FREEZE_ENABLE") = py::int_(LEP_CID_VID_FREEZE_ENABLE);
    handle.attr("LEPTON_COLOR_LUT_SIZE") = py::int_(LEPTON_COLOR_LUT_SIZE);

    py::enum_<LEP_POLARITY_E_TAG>(handle,"LEP_POLARITY_E_TAG")
        .value("LEP_VID_WHITE_HOT",LEP_POLARITY_E_TAG::LEP_VID_WHITE_HOT)
        .value("LEP_VID_BLACK_HOT",LEP_POLARITY_E_TAG::LEP_VID_BLACK_HOT)
        .value("LEP_VID_END_POLARITY",LEP_POLARITY_E_TAG::LEP_VID_END_POLARITY)
        .export_values();

    py::enum_<LEP_PCOLOR_LUT_E_TAG>(handle,"LEP_PCOLOR_LUT_E_TAG")
        .value("LEP_VID_WHEEL6_LUT",LEP_PCOLOR_LUT_E_TAG::LEP_VID_WHEEL6_LUT)
        .value("LEP_VID_FUSION_LUT",LEP_PCOLOR_LUT_E_TAG::LEP_VID_FUSION_LUT)
        .value("LEP_VID_RAINBOW_LUT",LEP_PCOLOR_LUT_E_TAG::LEP_VID_RAINBOW_LUT)
        .value("LEP_VID_GLOBOW_LUT",LEP_PCOLOR_LUT_E_TAG::LEP_VID_GLOBOW_LUT)
        .value("LEP_VID_SEPIA_LUT",LEP_PCOLOR_LUT_E_TAG::LEP_VID_SEPIA_LUT)
        .value("LEP_VID_COLOR_LUT",LEP_PCOLOR_LUT_E_TAG::LEP_VID_COLOR_LUT)
        .value("LEP_VID_ICE_FIRE_LUT",LEP_PCOLOR_LUT_E_TAG::LEP_VID_ICE_FIRE_LUT)
        .value("LEP_VID_RAIN_LUT",LEP_PCOLOR_LUT_E_TAG::LEP_VID_RAIN_LUT)
        .value("LEP_VID_USER_LUT",LEP_PCOLOR_LUT_E_TAG::LEP_VID_USER_LUT)
        .value("LEP_VID_END_PCOLOR_LUT",LEP_PCOLOR_LUT_E_TAG::LEP_VID_END_PCOLOR_LUT)
        .export_values();

    py::class_<LEP_VID_LUT_PIXEL_T_TAG>(handle,"LEP_VID_LUT_PIXEL_T_TAG")
        .def(py::init<>())
        .def_readwrite("reserved",&LEP_VID_LUT_PIXEL_T_TAG::reserved)
        .def_readwrite("red",&LEP_VID_LUT_PIXEL_T_TAG::red)
        .def_readwrite("green",&LEP_VID_LUT_PIXEL_T_TAG::green)
        .def_readwrite("blue",&LEP_VID_LUT_PIXEL_T_TAG::blue);

    py::class_<LEP_VID_LUT_BUFFER_T_TAG>(handle,"LEP_VID_LUT_BUFFER_T_TAG")
        .def(py::init<>())
        // .def_readwrite("bin",&LEP_VID_LUT_BUFFER_T_TAG::bin);
        .def_property("bin", [](LEP_VID_LUT_BUFFER_T_TAG &p)->py::array {
            auto dtype = py::dtype(py::format_descriptor<LEP_VID_LUT_PIXEL_T_TAG>::format());
            return py::array(dtype, { 256 }, { sizeof(LEP_VID_LUT_PIXEL_T_TAG) }, p.bin, nullptr);
        }, [](LEP_VID_LUT_BUFFER_T_TAG& p) {});

    py::enum_<LEP_VID_ENABLE_TAG>(handle,"LEP_VID_ENABLE_TAG")
        .value("LEP_VID_FOCUS_CALC_DISABLE",LEP_VID_ENABLE_TAG::LEP_VID_FOCUS_CALC_DISABLE)
        .value("LEP_VID_FOCUS_CALC_ENABLE",LEP_VID_ENABLE_TAG::LEP_VID_FOCUS_CALC_ENABLE)
        .value("LEP_VID_END_FOCUS_CALC_ENABLE",LEP_VID_ENABLE_TAG::LEP_VID_END_FOCUS_CALC_ENABLE)
        .export_values();

    py::class_<LEP_VID_FOCUS_ROI_TAG>(handle,"LEP_VID_FOCUS_ROI_TAG")
        .def(py::init<>())
        .def_readwrite("startCol",&LEP_VID_FOCUS_ROI_TAG::startCol)
        .def_readwrite("startRow",&LEP_VID_FOCUS_ROI_TAG::startRow)
        .def_readwrite("endCol",&LEP_VID_FOCUS_ROI_TAG::endCol)
        .def_readwrite("endRow",&LEP_VID_FOCUS_ROI_TAG::endRow);

    py::enum_<LEP_VID_SBNUC_ENABLE_TAG>(handle,"LEP_VID_SBNUC_ENABLE_TAG")
        .value("LEP_VID_SBNUC_DISABLE",LEP_VID_SBNUC_ENABLE_TAG::LEP_VID_SBNUC_DISABLE)
        .value("LEP_VID_SBNUC_ENABLE",LEP_VID_SBNUC_ENABLE_TAG::LEP_VID_SBNUC_ENABLE)
        .value("LEP_VID_END_SBNUC_ENABLE",LEP_VID_SBNUC_ENABLE_TAG::LEP_VID_END_SBNUC_ENABLE)
        .export_values();

    py::enum_<LEP_VID_FREEZE_ENABLE_TAG>(handle,"LEP_VID_FREEZE_ENABLE_TAG")
        .value("LEP_VID_FREEZE_DISABLE",LEP_VID_FREEZE_ENABLE_TAG::LEP_VID_FREEZE_DISABLE)
        .value("LEP_VID_FREEZE_ENABLE",LEP_VID_FREEZE_ENABLE_TAG::LEP_VID_FREEZE_ENABLE)
        .value("LEP_VID_END_FREEZE_ENABLE",LEP_VID_FREEZE_ENABLE_TAG::LEP_VID_END_FREEZE_ENABLE)
        .export_values();

    handle.def("LEP_GetVidPolarity",&LEP_GetVidPolarity);
    handle.def("LEP_SetVidPolarity",&LEP_SetVidPolarity);
    handle.def("LEP_GetVidPcolorLut",&LEP_GetVidPcolorLut);
    handle.def("LEP_SetVidPcolorLut",&LEP_SetVidPcolorLut);
    handle.def("LEP_GetVidUserLut",&LEP_GetVidUserLut);
    handle.def("LEP_SetVidUserLut",&LEP_SetVidUserLut);
    handle.def("LEP_GetVidFocusCalcEnableState",&LEP_GetVidFocusCalcEnableState);
    handle.def("LEP_SetVidFocusCalcEnableState",&LEP_SetVidFocusCalcEnableState);
    handle.def("LEP_GetVidROI",&LEP_GetVidROI);
    handle.def("LEP_SetVidROI",&LEP_SetVidROI);
    handle.def("LEP_GetVidFocusMetric",&LEP_GetVidFocusMetric);
    handle.def("LEP_GetVidFocusMetricThreshold",&LEP_GetVidFocusMetricThreshold);
    handle.def("LEP_SetVidFocusMetricThreshold",&LEP_SetVidFocusMetricThreshold);
    handle.def("LEP_GetVidSbNucEnableState",&LEP_GetVidSbNucEnableState);
    handle.def("LEP_SetVidSbNucEnableState",&LEP_SetVidSbNucEnableState);
}