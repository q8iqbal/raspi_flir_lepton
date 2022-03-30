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

#include "../sdk/LEPTON_AGC.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_agc, handle){
    handle.doc() = "Lepton SDK AGC Module Command Interface";

    handle.attr("LEP_AGC_MODULE_BASE") = py::int_(LEP_AGC_MODULE_BASE);

    handle.attr("LEP_CID_AGC_ENABLE_STATE") = py::int_(LEP_CID_AGC_ENABLE_STATE);
    handle.attr("LEP_CID_AGC_POLICY") = py::int_(LEP_CID_AGC_POLICY);
    handle.attr("LEP_CID_AGC_ROI") = py::int_(LEP_CID_AGC_ROI);
    handle.attr("LEP_CID_AGC_STATISTICS") = py::int_(LEP_CID_AGC_STATISTICS);
    handle.attr("LEP_CID_AGC_HISTOGRAM_CLIP_PERCENT") = py::int_(LEP_CID_AGC_HISTOGRAM_CLIP_PERCENT);
    handle.attr("LEP_CID_AGC_HISTOGRAM_TAIL_SIZE") = py::int_(LEP_CID_AGC_HISTOGRAM_TAIL_SIZE);
    handle.attr("LEP_CID_AGC_LINEAR_MAX_GAIN") = py::int_(LEP_CID_AGC_LINEAR_MAX_GAIN);
    handle.attr("LEP_CID_AGC_LINEAR_MIDPOINT") = py::int_(LEP_CID_AGC_LINEAR_MIDPOINT);
    handle.attr("LEP_CID_AGC_LINEAR_DAMPENING_FACTOR") = py::int_(LEP_CID_AGC_LINEAR_DAMPENING_FACTOR);
    handle.attr("LEP_CID_AGC_HEQ_DAMPENING_FACTOR") = py::int_(LEP_CID_AGC_HEQ_DAMPENING_FACTOR);
    handle.attr("LEP_CID_AGC_HEQ_MAX_GAIN") = py::int_(LEP_CID_AGC_HEQ_MAX_GAIN);
    handle.attr("LEP_CID_AGC_HEQ_CLIP_LIMIT_HIGH") = py::int_(LEP_CID_AGC_HEQ_CLIP_LIMIT_HIGH);
    handle.attr("LEP_CID_AGC_HEQ_CLIP_LIMIT_LOW") = py::int_(LEP_CID_AGC_HEQ_CLIP_LIMIT_LOW);
    handle.attr("LEP_CID_AGC_HEQ_BIN_EXTENSION") = py::int_(LEP_CID_AGC_HEQ_BIN_EXTENSION);
    handle.attr("LEP_CID_AGC_HEQ_MIDPOINT") = py::int_(LEP_CID_AGC_HEQ_MIDPOINT);
    handle.attr("LEP_CID_AGC_HEQ_EMPTY_COUNTS") = py::int_(LEP_CID_AGC_HEQ_EMPTY_COUNTS);
    handle.attr("LEP_CID_AGC_HEQ_NORMALIZATION_FACTOR") = py::int_(LEP_CID_AGC_HEQ_NORMALIZATION_FACTOR);
    handle.attr("LEP_CID_AGC_HEQ_SCALE_FACTOR") = py::int_(LEP_CID_AGC_HEQ_SCALE_FACTOR);
    handle.attr("LEP_CID_AGC_CALC_ENABLE_STATE") = py::int_(LEP_CID_AGC_CALC_ENABLE_STATE);

    handle.attr("LEP_AGC_MAX_HISTOGRAM_CLIP_PERCENT") = py::int_(LEP_AGC_MAX_HISTOGRAM_CLIP_PERCENT);
    handle.attr("LEP_AGC_MAX_HISTOGRAM_TAIL_SIZE") = py::int_(LEP_AGC_MAX_HISTOGRAM_TAIL_SIZE);
    handle.attr("LEP_AGC_MIN_LINEAR_MAX_GAIN") = py::int_(LEP_AGC_MIN_LINEAR_MAX_GAIN);
    handle.attr("LEP_AGC_MAX_LINEAR_MAX_GAIN") = py::int_(LEP_AGC_MAX_LINEAR_MAX_GAIN);
    handle.attr("LEP_AGC_MIN_LINEAR_MIDPOINT") = py::int_(LEP_AGC_MIN_LINEAR_MIDPOINT);
    handle.attr("LEP_AGC_MAX_LINEAR_MIDPOINT") = py::int_(LEP_AGC_MAX_LINEAR_MIDPOINT);
    handle.attr("LEP_AGC_MAX_LINEAR_DAMPENING_FACTOR") = py::int_(LEP_AGC_MAX_LINEAR_DAMPENING_FACTOR);

    handle.attr("LEP_AGC_MAX_HEQ_DAMPENING_FACTOR") = py::int_(LEP_AGC_MAX_HEQ_DAMPENING_FACTOR);
    handle.attr("LEP_AGC_MIN_HEQ_MAX_GAIN") = py::int_(LEP_AGC_MIN_HEQ_MAX_GAIN);
    handle.attr("LEP_AGC_MAX_HEQ_MAX_GAIN") = py::int_(LEP_AGC_MAX_HEQ_MAX_GAIN);

    handle.attr("LEP_AGC_HEQ_CLIP_LIMIT_HIGH") = py::int_(LEP_AGC_HEQ_CLIP_LIMIT_HIGH);
    handle.attr("LEP_AGC_HEQ_CLIP_LIMIT_LOW") = py::int_(LEP_AGC_HEQ_CLIP_LIMIT_LOW);
    handle.attr("LEP_AGC_HEQ_MAX_BIN_EXTENSION") = py::int_(LEP_AGC_HEQ_MAX_BIN_EXTENSION);

    handle.attr("LEP_AGC_MIN_HEQ_MIDPOINT") = py::int_(LEP_AGC_MIN_HEQ_MIDPOINT);
    handle.attr("LEP_AGC_MAX_HEQ_MIDPOINT") = py::int_(LEP_AGC_MAX_HEQ_MIDPOINT);

    handle.attr("LEP_AGC_MAX_COL") = py::int_(LEP_AGC_MAX_COL);
    handle.attr("LEP_AGC_MAX_ROW") = py::int_(LEP_AGC_MAX_ROW);
    handle.attr("LEP_AGC_MIN_COL") = py::int_(LEP_AGC_MIN_COL);
    handle.attr("LEP_AGC_MIN_ROW") = py::int_(LEP_AGC_MIN_ROW);

    py::enum_<LEP_AGC_ENABLE_TAG>(handle,"LEP_AGC_ENABLE_TAG")
        .value("LEP_AGC_DISABLE", LEP_AGC_ENABLE_TAG::LEP_AGC_DISABLE)
        .value("LEP_AGC_ENABLE", LEP_AGC_ENABLE_TAG::LEP_AGC_ENABLE)
        .value("LEP_END_AGC_ENABLE", LEP_AGC_ENABLE_TAG::LEP_END_AGC_ENABLE)
        .export_values();

    py::enum_<LEP_AGC_POLICY_TAG>(handle,"LEP_AGC_POLICY_TAG")
        .value("LEP_AGC_LINEAR", LEP_AGC_POLICY_TAG::LEP_AGC_LINEAR)
        .value("LEP_AGC_HEQ", LEP_AGC_POLICY_TAG::LEP_AGC_HEQ)
        .value("LEP_END_AGC_POLICY", LEP_AGC_POLICY_TAG::LEP_END_AGC_POLICY)
        .export_values();

    py::class_<LEP_AGC_ROI_TAG>(handle,"LEP_AGC_ROI_TAG")
        .def(py::init<>())
        .def_readwrite("startCol", &LEP_AGC_ROI_TAG::startCol)
        .def_readwrite("startRow", &LEP_AGC_ROI_TAG::startRow)
        .def_readwrite("endCol", &LEP_AGC_ROI_TAG::endCol)
        .def_readwrite("endRow", &LEP_AGC_ROI_TAG::endRow);

    py::class_<LEP_AGC_HISTOGRAM_STATISTICS_TAG>(handle,"LEP_AGC_HISTOGRAM_STATISTICS_TAG")
        .def(py::init<>())
        .def_readwrite("minIntensity", &LEP_AGC_HISTOGRAM_STATISTICS_TAG::minIntensity)
        .def_readwrite("maxIntensity", &LEP_AGC_HISTOGRAM_STATISTICS_TAG::maxIntensity)
        .def_readwrite("meanIntensity", &LEP_AGC_HISTOGRAM_STATISTICS_TAG::meanIntensity)
        .def_readwrite("numPixels", &LEP_AGC_HISTOGRAM_STATISTICS_TAG::numPixels);

    py::enum_<LEP_AGC_SCALE_FACTOR_E_TAG>(handle,"LEP_AGC_SCALE_FACTOR_E_TAG")
        .value("LEP_AGC_SCALE_TO_8_BITS", LEP_AGC_SCALE_FACTOR_E_TAG::LEP_AGC_SCALE_TO_8_BITS)
        .value("LEP_AGC_SCALE_TO_14_BITS", LEP_AGC_SCALE_FACTOR_E_TAG::LEP_AGC_SCALE_TO_14_BITS)
        .value("LEP_AGC_END_SCALE_TO", LEP_AGC_SCALE_FACTOR_E_TAG::LEP_AGC_END_SCALE_TO)
        .export_values();

    handle.def("LEP_GetAgcEnableState", &LEP_GetAgcCalcEnableState);
    handle.def("LEP_SetAgcEnableState", &LEP_SetAgcEnableState);
    handle.def("LEP_GetAgcPolicy", &LEP_GetAgcPolicy);
    handle.def("LEP_SetAgcPolicy", &LEP_SetAgcPolicy);
    handle.def("LEP_GetAgcROI", &LEP_GetAgcROI);
    handle.def("LEP_SetAgcROI", &LEP_SetAgcROI);
    // handle.def("LEP_GetAgcHistogramStatistics", &LEP_GetAgcHistogramStatistics);
    handle.def("LEP_GetAgcHistogramStatistics", [](LEP_CAMERA_PORT_DESC_T_PTR portDescPtr,
                                                 LEP_AGC_HISTOGRAM_STATISTICS_T *agcHistogramStatisticsPtr){
        return LEP_GetAgcHistogramStatistics(portDescPtr, &agcHistogramStatisticsPtr);
    });

    handle.def("LEP_GetAgcLinearHistogramTailSize", &LEP_GetAgcLinearHistogramTailSize);
    handle.def("LEP_SetAgcLinearHistogramTailSize", &LEP_SetAgcLinearHistogramTailSize);
    handle.def("LEP_GetAgcLinearHistogramClipPercent", &LEP_GetAgcLinearHistogramClipPercent);
    handle.def("LEP_SetAgcLinearHistogramClipPercent", &LEP_SetAgcLinearHistogramClipPercent);
    handle.def("LEP_GetAgcLinearMaxGain", &LEP_GetAgcLinearMaxGain);
    handle.def("LEP_SetAgcLinearMaxGain", &LEP_SetAgcLinearMaxGain);
    handle.def("LEP_GetAgcLinearMidPoint", &LEP_GetAgcLinearMidPoint);
    handle.def("LEP_SetAgcLinearMidPoint", &LEP_SetAgcLinearMidPoint);
    handle.def("LEP_GetAgcLinearDampeningFactor", &LEP_GetAgcLinearDampeningFactor);
    handle.def("LEP_SetAgcLinearDampeningFactor", &LEP_SetAgcLinearDampeningFactor);

    handle.def("LEP_GetAgcHeqDampingFactor", &LEP_GetAgcHeqDampingFactor);
    handle.def("LEP_SetAgcHeqDampingFactor", &LEP_SetAgcHeqDampingFactor);
    handle.def("LEP_GetAgcHeqMaxGain", &LEP_GetAgcHeqMaxGain);
    handle.def("LEP_SetAgcHeqMaxGain", &LEP_SetAgcHeqMaxGain);
    handle.def("LEP_GetAgcHeqClipLimitHigh", &LEP_GetAgcHeqClipLimitHigh);
    handle.def("LEP_SetAgcHeqClipLimitHigh", &LEP_SetAgcHeqClipLimitHigh);
    handle.def("LEP_GetAgcHeqClipLimitLow", &LEP_GetAgcHeqClipLimitLow);
    handle.def("LEP_SetAgcHeqClipLimitLow", &LEP_SetAgcHeqClipLimitLow);
    handle.def("LEP_GetAgcHeqBinExtension", &LEP_GetAgcHeqBinExtension);
    handle.def("LEP_SetAgcHeqBinExtension", &LEP_SetAgcHeqBinExtension);
    handle.def("LEP_GetAgcHeqMidPoint", &LEP_GetAgcHeqMidPoint);
    handle.def("LEP_SetAgcHeqMidPoint", &LEP_SetAgcHeqMidPoint);
    handle.def("LEP_GetAgcHeqEmptyCount", &LEP_GetAgcHeqEmptyCount);
    handle.def("LEP_SetAgcHeqEmptyCount", &LEP_SetAgcHeqEmptyCount);
    handle.def("LEP_GetAgcHeqNormalizationFactor", &LEP_GetAgcHeqNormalizationFactor);
    handle.def("LEP_SetAgcHeqNormalizationFactor", &LEP_SetAgcHeqNormalizationFactor);
    handle.def("LEP_GetAgcHeqScaleFactor", &LEP_GetAgcHeqScaleFactor);
    handle.def("LEP_SetAgcHeqScaleFactor", &LEP_SetAgcHeqScaleFactor);
    handle.def("LEP_GetAgcCalcEnableState", &LEP_GetAgcCalcEnableState);
    handle.def("LEP_SetAgcCalcEnableState", &LEP_SetAgcCalcEnableState);
}