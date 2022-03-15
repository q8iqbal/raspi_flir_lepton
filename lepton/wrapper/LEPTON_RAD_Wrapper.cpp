#include <pybind11/pybind11.h>

#include "../sdk/LEPTON_RAD.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_rad, handle){
    handle.doc() = "dunno wat dis is for";

    handle.attr("LEP_RAD_TEMPERATURE_SCALE_FACTOR") = py::int_(LEP_RAD_TEMPERATURE_SCALE_FACTOR);
    handle.attr("LEP_RAD_RBFO_SCALE_SHIFT") = py::int_(LEP_RAD_RBFO_SCALE_SHIFT);
    handle.attr("LEP_RAD_LUT128_ENTRIES") = py::int_(LEP_RAD_LUT128_ENTRIES);
    handle.attr("LEP_RAD_MODULE_BASE") = py::int_(LEP_RAD_MODULE_BASE);
    handle.attr("LEP_CID_RAD_RBFO_INTERNAL") = py::int_(LEP_CID_RAD_RBFO_INTERNAL);
    handle.attr("LEP_CID_RAD_RBFO_EXTERNAL") = py::int_(LEP_CID_RAD_RBFO_EXTERNAL);
    handle.attr("LEP_CID_RAD_DEBUG_TEMP") = py::int_(LEP_CID_RAD_DEBUG_TEMP);
    handle.attr("LEP_CID_RAD_DEBUG_FLUX") = py::int_(LEP_CID_RAD_DEBUG_FLUX);
    handle.attr("LEP_CID_RAD_ENABLE_STATE") = py::int_(LEP_CID_RAD_ENABLE_STATE);
    handle.attr("LEP_CID_RAD_GLOBAL_OFFSET") = py::int_(LEP_CID_RAD_GLOBAL_OFFSET);
    handle.attr("LEP_CID_RAD_TFPA_CTS_MODE") = py::int_(LEP_CID_RAD_TFPA_CTS_MODE);
    handle.attr("LEP_CID_RAD_TFPA_CTS") = py::int_(LEP_CID_RAD_TFPA_CTS);
    handle.attr("LEP_CID_RAD_TEQ_SHUTTER_LUT") = py::int_(LEP_CID_RAD_TEQ_SHUTTER_LUT);
    handle.attr("LEP_CID_RAD_TSHUTTER_MODE") = py::int_(LEP_CID_RAD_TSHUTTER_MODE);
    handle.attr("LEP_CID_RAD_TSHUTTER") = py::int_(LEP_CID_RAD_TSHUTTER);
    handle.attr("LEP_CID_RAD_RUN_FFC") = py::int_(LEP_CID_RAD_RUN_FFC);
    handle.attr("LEP_CID_RAD_RUN_STATUS") = py::int_(LEP_CID_RAD_RUN_STATUS);
    handle.attr("LEP_CID_RAD_RESPONSIVITY_SHIFT") = py::int_(LEP_CID_RAD_RESPONSIVITY_SHIFT);
    handle.attr("LEP_CID_RAD_F_NUMBER") = py::int_(LEP_CID_RAD_F_NUMBER);
    handle.attr("LEP_CID_RAD_TAU_LENS") = py::int_(LEP_CID_RAD_TAU_LENS);
    handle.attr("LEP_CID_RAD_RESPONSIVITY_VALUE_LUT") = py::int_(LEP_CID_RAD_RESPONSIVITY_VALUE_LUT);
    handle.attr("LEP_CID_RAD_GLOBAL_GAIN") = py::int_(LEP_CID_RAD_GLOBAL_GAIN);
    handle.attr("LEP_CID_RAD_RADIOMETRY_FILTER") = py::int_(LEP_CID_RAD_RADIOMETRY_FILTER);
    handle.attr("LEP_CID_RAD_TFPA_LUT") = py::int_(LEP_CID_RAD_TFPA_LUT);
    handle.attr("LEP_CID_RAD_TAUX_LUT") = py::int_(LEP_CID_RAD_TAUX_LUT);
    handle.attr("LEP_CID_RAD_TAUX_CTS_MODE") = py::int_(LEP_CID_RAD_TAUX_CTS_MODE);
    handle.attr("LEP_CID_RAD_TAUX_CTS") = py::int_(LEP_CID_RAD_TAUX_CTS);
    handle.attr("LEP_CID_RAD_TEQ_SHUTTER_FLUX") = py::int_(LEP_CID_RAD_TEQ_SHUTTER_FLUX);
    handle.attr("LEP_CID_RAD_MFFC_FLUX") = py::int_(LEP_CID_RAD_MFFC_FLUX);
    handle.attr("LEP_CID_RAD_FRAME_MEDIAN_VALUE") = py::int_(LEP_CID_RAD_FRAME_MEDIAN_VALUE);
    handle.attr("LEP_CID_RAD_MLG_LUT") = py::int_(LEP_CID_RAD_MLG_LUT);
    handle.attr("LEP_CID_RAD_THOUSING_TCP") = py::int_(LEP_CID_RAD_THOUSING_TCP);
    handle.attr("LEP_CID_RAD_HOUSING_TCP") = py::int_(LEP_CID_RAD_HOUSING_TCP);
    handle.attr("LEP_CID_RAD_SHUTTER_TCP") = py::int_(LEP_CID_RAD_SHUTTER_TCP);
    handle.attr("LEP_CID_RAD_LENS_TCP") = py::int_(LEP_CID_RAD_LENS_TCP);
    handle.attr("LEP_CID_RAD_PREVIOUS_GLOBAL_OFFSET") = py::int_(LEP_CID_RAD_PREVIOUS_GLOBAL_OFFSET);
    handle.attr("LEP_CID_RAD_PREVIOUS_GLOBAL_GAIN") = py::int_(LEP_CID_RAD_PREVIOUS_GLOBAL_GAIN);
    handle.attr("LEP_CID_RAD_GLOBAL_GAIN_FFC") = py::int_(LEP_CID_RAD_GLOBAL_GAIN_FFC);
    handle.attr("LEP_CID_RAD_CNF_SCALE_FACTOR") = py::int_(LEP_CID_RAD_CNF_SCALE_FACTOR);
    handle.attr("LEP_CID_RAD_TNF_SCALE_FACTOR") = py::int_(LEP_CID_RAD_TNF_SCALE_FACTOR);
    handle.attr("LEP_CID_RAD_SNF_SCALE_FACTOR") = py::int_(LEP_CID_RAD_SNF_SCALE_FACTOR);
    handle.attr("LEP_CID_RAD_ARBITRARY_OFFSET") = py::int_(LEP_CID_RAD_ARBITRARY_OFFSET);
    handle.attr("LEP_CID_RAD_FLUX_LINEAR_PARAMS") = py::int_(LEP_CID_RAD_FLUX_LINEAR_PARAMS);
    handle.attr("LEP_CID_RAD_TLINEAR_ENABLE_STATE") = py::int_(LEP_CID_RAD_TLINEAR_ENABLE_STATE);
    handle.attr("LEP_CID_RAD_TLINEAR_RESOLUTION") = py::int_(LEP_CID_RAD_TLINEAR_RESOLUTION);
    handle.attr("LEP_CID_RAD_TLINEAR_AUTO_RESOLUTION") = py::int_(LEP_CID_RAD_TLINEAR_AUTO_RESOLUTION);
    handle.attr("LEP_CID_RAD_SPOTMETER_ROI") = py::int_(LEP_CID_RAD_SPOTMETER_ROI);
    handle.attr("LEP_CID_RAD_SPOTMETER_OBJ_KELVIN") = py::int_(LEP_CID_RAD_SPOTMETER_OBJ_KELVIN);
    handle.attr("LEP_CID_RAD_RBFO_INTERNAL_LG") = py::int_(LEP_CID_RAD_RBFO_INTERNAL_LG);
    handle.attr("LEP_CID_RAD_RBFO_EXTERNAL_LG") = py::int_(LEP_CID_RAD_RBFO_EXTERNAL_LG);
    handle.attr("LEP_CID_RAD_ARBITRARY_OFFSET_MODE") = py::int_(LEP_CID_RAD_ARBITRARY_OFFSET_MODE);
    handle.attr("LEP_CID_RAD_ARBITRARY_OFFSET_PARAMS") = py::int_(LEP_CID_RAD_ARBITRARY_OFFSET_PARAMS);
    handle.attr("LEP_CID_RAD_RADIO_CAL_VALUES") = py::int_(LEP_CID_RAD_RADIO_CAL_VALUES);

    py::enum_<LEP_RAD_TS_MODE_E>(handle,"LEP_RAD_TS_MODE_E")
        .value("LEP_RAD_TS_USER_MODE",LEP_RAD_TS_MODE_E::LEP_RAD_TS_USER_MODE)
        .value("LEP_RAD_TS_CAL_MODE",LEP_RAD_TS_MODE_E::LEP_RAD_TS_CAL_MODE)
        .value("LEP_RAD_TS_FIXED_MODE",LEP_RAD_TS_MODE_E::LEP_RAD_TS_FIXED_MODE)
        .value("LEP_RAD_TS_END_TS_MODE",LEP_RAD_TS_MODE_E::LEP_RAD_TS_END_TS_MODE)
        .export_values();

    py::class_<LEP_RBFO_T>(handle,"LEP_RBFO_T")
        .def(py::init<>())
        .def_readwrite("RBFO_R",&LEP_RBFO_T::RBFO_R)
        .def_readwrite("RBFO_B",&LEP_RBFO_T::RBFO_B)
        .def_readwrite("RBFO_F",&LEP_RBFO_T::RBFO_F)
        .def_readwrite("RBFO_O",&LEP_RBFO_T::RBFO_O);

    py::class_<LEP_RAD_LINEAR_TEMP_CORRECTION_T>(handle,"LEP_RAD_LINEAR_TEMP_CORRECTION_T")
        .def(py::init<>())
        .def_readwrite("offset",&LEP_RAD_LINEAR_TEMP_CORRECTION_T::offset)
        .def_readwrite("gainAux",&LEP_RAD_LINEAR_TEMP_CORRECTION_T::gainAux)
        .def_readwrite("gainShutter",&LEP_RAD_LINEAR_TEMP_CORRECTION_T::gainShutter)
        .def_readwrite("pad",&LEP_RAD_LINEAR_TEMP_CORRECTION_T::pad);

    py::enum_<LEP_RAD_ENABLE_E>(handle,"LEP_RAD_ENABLE_E")
        .value("LEP_RAD_DISABLE",LEP_RAD_ENABLE_E::LEP_RAD_DISABLE)
        .value("LEP_RAD_ENABLE",LEP_RAD_ENABLE_E::LEP_RAD_ENABLE)
        .value("LEP_END_RAD_ENABLE",LEP_RAD_ENABLE_E::LEP_END_RAD_ENABLE)
        .export_values();

    py::enum_<LEP_RAD_TEMPERATURE_UPDATE_E>(handle,"LEP_RAD_TEMPERATURE_UPDATE_E")
        .value("LEP_RAD_NORMAL_UPDATE",LEP_RAD_TEMPERATURE_UPDATE_E::LEP_RAD_NORMAL_UPDATE)
        .value("LEP_RAD_NO_UPDATE",LEP_RAD_TEMPERATURE_UPDATE_E::LEP_RAD_NO_UPDATE)
        .value("LEP_RAD_UPDATE_END",LEP_RAD_TEMPERATURE_UPDATE_E::LEP_RAD_UPDATE_END)
        .export_values();

    py::enum_<LEP_RAD_STATUS_E>(handle,"LEP_RAD_STATUS_E")
        .value("LEP_RAD_STATUS_ERROR",LEP_RAD_STATUS_E::LEP_RAD_STATUS_ERROR)
        .value("LEP_RAD_STATUS_READY",LEP_RAD_STATUS_E::LEP_RAD_STATUS_READY)
        .value("LEP_RAD_STATUS_BUSY",LEP_RAD_STATUS_E::LEP_RAD_STATUS_BUSY)
        .value("LEP_RAD_FRAME_AVERAGE_COLLECTING_FRAMES",LEP_RAD_STATUS_E::LEP_RAD_FRAME_AVERAGE_COLLECTING_FRAMES)
        .value("LEP_RAD_STATUS_END",LEP_RAD_STATUS_E::LEP_RAD_STATUS_END)
        .export_values();

    py::class_<LEP_RAD_FLUX_LINEAR_PARAMS_T_TAG>(handle,"LEP_RAD_FLUX_LINEAR_PARAMS_T_TAG")
        .def(py::init<>())
        .def_readwrite("sceneEmissivity",&LEP_RAD_FLUX_LINEAR_PARAMS_T_TAG::sceneEmissivity)
        .def_readwrite("TBkgK",&LEP_RAD_FLUX_LINEAR_PARAMS_T_TAG::TBkgK)
        .def_readwrite("tauWindow",&LEP_RAD_FLUX_LINEAR_PARAMS_T_TAG::tauWindow)
        .def_readwrite("TWindowK",&LEP_RAD_FLUX_LINEAR_PARAMS_T_TAG::TWindowK)
        .def_readwrite("tauAtm",&LEP_RAD_FLUX_LINEAR_PARAMS_T_TAG::tauAtm)
        .def_readwrite("TAtmK",&LEP_RAD_FLUX_LINEAR_PARAMS_T_TAG::TAtmK)
        .def_readwrite("reflWindow",&LEP_RAD_FLUX_LINEAR_PARAMS_T_TAG::reflWindow)
        .def_readwrite("TReflK",&LEP_RAD_FLUX_LINEAR_PARAMS_T_TAG::TReflK);

    py::enum_<LEP_RAD_TLINEAR_RESOLUTION_E>(handle,"LEP_RAD_TLINEAR_RESOLUTION_E")
        .value("LEP_RAD_RESOLUTION_0_1",LEP_RAD_TLINEAR_RESOLUTION_E::LEP_RAD_RESOLUTION_0_1)
        .value("LEP_RAD_RESOLUTION_0_01",LEP_RAD_TLINEAR_RESOLUTION_E::LEP_RAD_RESOLUTION_0_01)
        .value("LEP_RAD_END_RESOLUTION",LEP_RAD_TLINEAR_RESOLUTION_E::LEP_RAD_END_RESOLUTION)
        .export_values();

    py::class_<LEP_RAD_ROI_T>(handle,"LEP_RAD_ROI_T")
        .def(py::init<>())
        .def_readwrite("startRow",&LEP_RAD_ROI_T::startRow)
        .def_readwrite("startCol",&LEP_RAD_ROI_T::startCol)
        .def_readwrite("endRow",&LEP_RAD_ROI_T::endRow)
        .def_readwrite("endCol",&LEP_RAD_ROI_T::endCol);

    py::enum_<LEP_RAD_ARBITRARY_OFFSET_MODE_E>(handle,"LEP_RAD_ARBITRARY_OFFSET_MODE_E")
        .value("LEP_RAD_ARBITRARY_OFFSET_MODE_MANUAL",LEP_RAD_ARBITRARY_OFFSET_MODE_E::LEP_RAD_ARBITRARY_OFFSET_MODE_MANUAL)
        .value("LEP_RAD_ARBITRARY_OFFSET_MODE_AUTO",LEP_RAD_ARBITRARY_OFFSET_MODE_E::LEP_RAD_ARBITRARY_OFFSET_MODE_AUTO)
        .value("LEP_RAD_END_ARBITRARY_OFFSET_MODE",LEP_RAD_ARBITRARY_OFFSET_MODE_E::LEP_RAD_END_ARBITRARY_OFFSET_MODE)
        .export_values();

    py::class_<LEP_RAD_ARBITRARY_OFFSET_PARAMS_T>(handle,"LEP_RAD_ARBITRARY_OFFSET_PARAMS_T")
        .def(py::init<>())
        .def_readwrite("amplitude",&LEP_RAD_ARBITRARY_OFFSET_PARAMS_T::amplitude)
        .def_readwrite("decay",&LEP_RAD_ARBITRARY_OFFSET_PARAMS_T::decay);

    py::class_<LEP_RAD_SPOTMETER_OBJ_KELVIN_T>(handle,"LEP_RAD_SPOTMETER_OBJ_KELVIN_T")
        .def(py::init<>())
        .def_readwrite("radSpotmeterValue",&LEP_RAD_SPOTMETER_OBJ_KELVIN_T::radSpotmeterValue)
        .def_readwrite("radSpotmeterMaxValue",&LEP_RAD_SPOTMETER_OBJ_KELVIN_T::radSpotmeterMaxValue)
        .def_readwrite("radSpotmeterMinValue",&LEP_RAD_SPOTMETER_OBJ_KELVIN_T::radSpotmeterMinValue)
        .def_readwrite("radSpotmeterPopulation",&LEP_RAD_SPOTMETER_OBJ_KELVIN_T::radSpotmeterPopulation);

    py::class_<LEP_RAD_RADIO_CAL_VALUES_T>(handle,"LEP_RAD_RADIO_CAL_VALUES_T")
        .def(py::init<>())
        .def_readwrite("radTauxCounts",&LEP_RAD_RADIO_CAL_VALUES_T::radTauxCounts)
        .def_readwrite("radTfpaCounts",&LEP_RAD_RADIO_CAL_VALUES_T::radTfpaCounts)
        .def_readwrite("radTauxKelvin",&LEP_RAD_RADIO_CAL_VALUES_T::radTauxKelvin)
        .def_readwrite("radTfpaKelvin",&LEP_RAD_RADIO_CAL_VALUES_T::radTfpaKelvin);

    handle.def("LEP_GetRadTShutterMode",&LEP_GetRadTShutterMode);
    handle.def("LEP_SetRadTShutterMode",&LEP_SetRadTShutterMode);
    handle.def("LEP_GetRadTShutter",&LEP_GetRadTShutter);
    handle.def("LEP_SetRadTShutter",&LEP_SetRadTShutter);
    handle.def("LEP_RunRadFFC",&LEP_RunRadFFC);
    handle.def("LEP_GetRadRBFOInternal0",&LEP_GetRadRBFOInternal0);
    handle.def("LEP_SetRadRBFOInternal0",&LEP_SetRadRBFOInternal0);
    handle.def("LEP_GetRadRBFOExternal0",&LEP_GetRadRBFOExternal0);
    handle.def("LEP_SetRadRBFOExternal0",&LEP_SetRadRBFOExternal0);
    handle.def("LEP_GetRadResponsivityShift",&LEP_GetRadResponsivityShift);
    handle.def("LEP_SetRadResponsivityShift",&LEP_SetRadResponsivityShift);
    handle.def("LEP_GetRadFNumber",&LEP_GetRadFNumber);
    handle.def("LEP_SetRadFNumber",&LEP_SetRadFNumber);
    handle.def("LEP_GetRadTauLens",&LEP_GetRadTauLens);
    handle.def("LEP_SetRadTauLens",&LEP_SetRadTauLens);
    handle.def("LEP_GetRadRadometryFilter",&LEP_GetRadRadometryFilter);
    handle.def("LEP_SetRadRadometryFilter",&LEP_SetRadRadometryFilter);
    handle.def("LEP_GetRadTFpaLut",&LEP_GetRadTFpaLut);
    handle.def("LEP_SetRadTFpaLut",&LEP_SetRadTFpaLut);
    handle.def("LEP_GetRadTAuxLut",&LEP_GetRadTAuxLut);
    handle.def("LEP_SetRadTAuxLut",&LEP_SetRadTAuxLut);
    handle.def("LEP_GetRadResponsivityValueLut",&LEP_GetRadResponsivityValueLut);
    handle.def("LEP_SetRadResponsivityValueLut",&LEP_SetRadResponsivityValueLut);
    handle.def("LEP_GetRadDebugTemp",&LEP_GetRadDebugTemp);
    handle.def("LEP_SetRadDebugTemp",&LEP_SetRadDebugTemp);
    handle.def("LEP_GetRadDebugFlux",&LEP_GetRadDebugFlux);
    handle.def("LEP_SetRadDebugFlux",&LEP_SetRadDebugFlux);
    handle.def("LEP_GetRadEnableState",&LEP_GetRadEnableState);
    handle.def("LEP_SetRadEnableState",&LEP_SetRadEnableState);
    handle.def("LEP_GetRadGlobalGain",&LEP_GetRadGlobalGain);
    handle.def("LEP_SetRadGlobalGain",&LEP_SetRadGlobalGain);
    handle.def("LEP_SetRadGlobalOffset",&LEP_SetRadGlobalOffset);
    handle.def("LEP_GetRadTFpaCtsMode",&LEP_GetRadTFpaCtsMode);
    handle.def("LEP_SetRadTFpaCtsMode",&LEP_SetRadTFpaCtsMode);
    handle.def("LEP_GetRadTAuxCtsMode",&LEP_GetRadTAuxCtsMode);
    handle.def("LEP_SetRadTAuxCtsMode",&LEP_SetRadTAuxCtsMode);
    handle.def("LEP_GetRadTFpaCts",&LEP_GetRadTFpaCts);
    handle.def("LEP_SetRadTFpaCts",&LEP_SetRadTFpaCts);
    handle.def("LEP_GetRadTAuxCts",&LEP_GetRadTAuxCts);
    handle.def("LEP_SetRadTAuxCts",&LEP_SetRadTAuxCts);
    handle.def("LEP_GetRadTEqShutterLut",&LEP_GetRadTEqShutterLut);
    handle.def("LEP_SetRadTEqShutterLut",&LEP_SetRadTEqShutterLut);
    handle.def("LEP_GetRadRunStatus",&LEP_GetRadRunStatus);
    handle.def("LEP_GetRadTEqShutterFlux",&LEP_GetRadTEqShutterFlux);
    handle.def("LEP_SetRadTEqShutterFlux",&LEP_SetRadTEqShutterFlux);
    handle.def("LEP_GetRadMffcFlux",&LEP_GetRadMffcFlux);
    handle.def("LEP_SetRadMffcFlux",&LEP_SetRadMffcFlux);
    handle.def("LEP_GetRadFrameMedianPixelValue",&LEP_GetRadFrameMedianPixelValue);
    handle.def("LEP_GetRadMLGLut",&LEP_GetRadMLGLut);
    handle.def("LEP_SetRadMLGLut",&LEP_SetRadMLGLut);
    handle.def("LEP_GetRadHousingTcp",&LEP_GetRadHousingTcp);
    handle.def("LEP_SetRadHousingTcp",&LEP_SetRadHousingTcp);
    handle.def("LEP_GetRadShutterTcp",&LEP_GetRadShutterTcp);
    handle.def("LEP_SetRadShutterTcp",&LEP_SetRadShutterTcp);
    handle.def("LEP_GetRadLensTcp",&LEP_GetRadLensTcp);
    handle.def("LEP_SetRadLensTcp",&LEP_SetRadLensTcp);
    handle.def("LEP_GetRadPreviousGlobalOffset",&LEP_GetRadPreviousGlobalOffset);
    handle.def("LEP_GetRadPreviousGlobalGain",&LEP_GetRadPreviousGlobalGain);
    handle.def("LEP_GetGlobalGainFFC",&LEP_GetGlobalGainFFC);
    handle.def("LEP_GetRadCnfScaleFactor",&LEP_GetRadCnfScaleFactor);
    handle.def("LEP_GetRadTnfScaleFactor",&LEP_GetRadTnfScaleFactor);
    handle.def("LEP_GetRadSnfScaleFactor",&LEP_GetRadSnfScaleFactor);
    handle.def("LEP_GetRadArbitraryOffset",&LEP_GetRadArbitraryOffset);
    handle.def("LEP_SetRadArbitraryOffset",&LEP_SetRadArbitraryOffset);
    handle.def("LEP_GetRadFluxLinearParams",&LEP_GetRadFluxLinearParams);
    handle.def("LEP_SetRadFluxLinearParams",&LEP_SetRadFluxLinearParams);
    handle.def("LEP_GetRadTLinearEnableState",&LEP_GetRadTLinearEnableState);
    handle.def("LEP_SetRadTLinearEnableState",&LEP_SetRadTLinearEnableState);
    handle.def("LEP_GetRadTLinearResolution",&LEP_GetRadTLinearResolution);
    handle.def("LEP_SetRadTLinearResolution",&LEP_SetRadTLinearResolution);
    handle.def("LEP_GetRadTLinearAutoResolution",&LEP_GetRadTLinearAutoResolution);
    handle.def("LEP_SetRadTLinearAutoResolution",&LEP_SetRadTLinearAutoResolution);
    handle.def("LEP_GetRadSpotmeterRoi",&LEP_GetRadSpotmeterRoi);
    handle.def("LEP_SetRadSpotmeterRoi",&LEP_SetRadSpotmeterRoi);
    handle.def("LEP_GetRadSpotmeterObjInKelvinX100",&LEP_GetRadSpotmeterObjInKelvinX100);
    handle.def("LEP_GetRadArbitraryOffsetMode",&LEP_GetRadArbitraryOffsetMode);
    handle.def("LEP_SetRadArbitraryOffsetMode",&LEP_SetRadArbitraryOffsetMode);
    handle.def("LEP_GetRadArbitraryOffsetParams",&LEP_GetRadArbitraryOffsetParams);
    handle.def("LEP_SetRadArbitraryOffsetParams",&LEP_SetRadArbitraryOffsetParams);
    handle.def("LEP_GetRadInternalRBFOHighGain",&LEP_GetRadInternalRBFOHighGain);
    handle.def("LEP_SetRadInternalRBFOHighGain",&LEP_SetRadInternalRBFOHighGain);
    handle.def("LEP_GetRadExternalRBFOHighGain",&LEP_GetRadExternalRBFOHighGain);
    handle.def("LEP_SetRadExternalRBFOHighGain",&LEP_SetRadExternalRBFOHighGain);
    handle.def("LEP_GetRadInternalRBFOLowGain",&LEP_GetRadInternalRBFOLowGain);
    handle.def("LEP_SetRadInternalRBFOLowGain",&LEP_SetRadInternalRBFOLowGain);
    handle.def("LEP_GetRadExternalRBFOLowGain",&LEP_GetRadExternalRBFOLowGain);
    handle.def("LEP_SetRadExternalRBFOLowGain",&LEP_SetRadExternalRBFOLowGain);
    handle.def("LEP_GetRadRadioCalValues",&LEP_GetRadRadioCalValues);
    handle.def("LEP_SetRadRadioCalValues",&LEP_SetRadRadioCalValues);
}