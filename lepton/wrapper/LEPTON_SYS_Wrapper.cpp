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

#include "../sdk/LEPTON_SYS.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_sys, handle){
    handle.doc() = "Lepton SDK SYS (system) Module Command Interface";

    handle.attr("LEP_SYS_MODULE_BASE") = py::int_(LEP_SYS_MODULE_BASE);
    handle.attr("LEP_CID_SYS_PING") = py::int_(LEP_CID_SYS_PING);
    handle.attr("LEP_CID_SYS_CAM_STATUS") = py::int_(LEP_CID_SYS_CAM_STATUS);
    handle.attr("LEP_CID_SYS_FLIR_SERIAL_NUMBER") = py::int_(LEP_CID_SYS_FLIR_SERIAL_NUMBER);
    handle.attr("LEP_CID_SYS_CAM_UPTIME") = py::int_(LEP_CID_SYS_CAM_UPTIME);
    handle.attr("LEP_CID_SYS_AUX_TEMPERATURE_KELVIN") = py::int_(LEP_CID_SYS_AUX_TEMPERATURE_KELVIN);
    handle.attr("LEP_CID_SYS_FPA_TEMPERATURE_KELVIN") = py::int_(LEP_CID_SYS_FPA_TEMPERATURE_KELVIN);
    handle.attr("LEP_CID_SYS_TELEMETRY_ENABLE_STATE") = py::int_(LEP_CID_SYS_TELEMETRY_ENABLE_STATE);
    handle.attr("LEP_CID_SYS_TELEMETRY_LOCATION") = py::int_(LEP_CID_SYS_TELEMETRY_LOCATION);
    handle.attr("LEP_CID_SYS_EXECTUE_FRAME_AVERAGE") = py::int_(LEP_CID_SYS_EXECTUE_FRAME_AVERAGE);
    handle.attr("LEP_CID_SYS_NUM_FRAMES_TO_AVERAGE") = py::int_(LEP_CID_SYS_NUM_FRAMES_TO_AVERAGE);
    handle.attr("LEP_CID_SYS_CUST_SERIAL_NUMBER") = py::int_(LEP_CID_SYS_CUST_SERIAL_NUMBER);
    handle.attr("LEP_CID_SYS_SCENE_STATISTICS") = py::int_(LEP_CID_SYS_SCENE_STATISTICS);
    handle.attr("LEP_CID_SYS_SCENE_ROI") = py::int_(LEP_CID_SYS_SCENE_ROI);
    handle.attr("LEP_CID_SYS_THERMAL_SHUTDOWN_COUNT") = py::int_(LEP_CID_SYS_THERMAL_SHUTDOWN_COUNT);
    handle.attr("LEP_CID_SYS_SHUTTER_POSITION") = py::int_(LEP_CID_SYS_SHUTTER_POSITION);
    handle.attr("LEP_CID_SYS_FFC_SHUTTER_MODE_OBJ") = py::int_(LEP_CID_SYS_FFC_SHUTTER_MODE_OBJ);
    handle.attr("FLR_CID_SYS_RUN_FFC") = py::int_(FLR_CID_SYS_RUN_FFC);
    handle.attr("LEP_CID_SYS_FFC_STATUS") = py::int_(LEP_CID_SYS_FFC_STATUS);
    handle.attr("LEP_SYS_MAX_FRAMES_TO_AVERAGE") = py::int_(LEP_SYS_MAX_FRAMES_TO_AVERAGE);
    handle.attr("LEP_SYS_MAX_SERIAL_NUMBER_CHAR_SIZE") = py::int_(LEP_SYS_MAX_SERIAL_NUMBER_CHAR_SIZE);

    py::class_<LEP_SYS_CUST_SERIAL_NUMBER_T_TAG>(handle,"LEP_SYS_CUST_SERIAL_NUMBER_T_TAG")
        .def(py::init<>())
        // .def_readwrite("value", &LEP_SYS_CUST_SERIAL_NUMBER_T_TAG::value);
        .def_property("value", [](LEP_SYS_CUST_SERIAL_NUMBER_T_TAG &p)->py::array {
            auto dtype = py::dtype(py::format_descriptor<LEP_CHAR8>::format());
            return py::array(dtype, { LEP_SYS_MAX_SERIAL_NUMBER_CHAR_SIZE }, { sizeof(LEP_CHAR8) }, p.value, nullptr);
        }, [](LEP_SYS_CUST_SERIAL_NUMBER_T_TAG& p) {});

    py::enum_<LEP_SYSTEM_STATUS_STATES_E_TAG>(handle,"LEP_SYSTEM_STATUS_STATES_E_TAG")
        .value("LEP_SYSTEM_READY",LEP_SYSTEM_STATUS_STATES_E_TAG::LEP_SYSTEM_READY)
        .value("LEP_SYSTEM_INITIALIZING",LEP_SYSTEM_STATUS_STATES_E_TAG::LEP_SYSTEM_INITIALIZING)
        .value("LEP_SYSTEM_IN_LOW_POWER_MODE",LEP_SYSTEM_STATUS_STATES_E_TAG::LEP_SYSTEM_IN_LOW_POWER_MODE)
        .value("LEP_SYSTEM_GOING_INTO_STANDBY",LEP_SYSTEM_STATUS_STATES_E_TAG::LEP_SYSTEM_GOING_INTO_STANDBY)
        .value("LEP_SYSTEM_FLAT_FIELD_IN_PROCESS",LEP_SYSTEM_STATUS_STATES_E_TAG::LEP_SYSTEM_FLAT_FIELD_IN_PROCESS)
        .value("LEP_SYSTEM_END_STATES",LEP_SYSTEM_STATUS_STATES_E_TAG::LEP_SYSTEM_END_STATES)
        .export_values();

    py::class_<LEP_STATUS_T>(handle,"LEP_STATUS_T")
        .def(py::init<>())
        .def_readwrite("camStatus", &LEP_STATUS_T::camStatus)
        .def_readwrite("commandCount", &LEP_STATUS_T::commandCount)
        .def_readwrite("reserved", &LEP_STATUS_T::reserved);

    py::enum_<LEP_SYS_TELEMETRY_ENABLE_STATE_E_TAG>(handle,"LEP_SYS_TELEMETRY_ENABLE_STATE_E_TAG")
        .value("LEP_TELEMETRY_DISABLED",LEP_SYS_TELEMETRY_ENABLE_STATE_E_TAG::LEP_TELEMETRY_DISABLED)
        .value("LEP_TELEMETRY_ENABLED",LEP_SYS_TELEMETRY_ENABLE_STATE_E_TAG::LEP_TELEMETRY_ENABLED)
        .value("LEP_END_TELEMETRY_ENABLE_STATE",LEP_SYS_TELEMETRY_ENABLE_STATE_E_TAG::LEP_END_TELEMETRY_ENABLE_STATE)
        .export_values();

    py::enum_<LEP_SYS_TELEMETRY_LOCATION_E_TAG>(handle,"LEP_SYS_TELEMETRY_LOCATION_E_TAG")
        .value("LEP_TELEMETRY_LOCATION_HEADER",LEP_SYS_TELEMETRY_LOCATION_E_TAG::LEP_TELEMETRY_LOCATION_HEADER)
        .value("LEP_TELEMETRY_LOCATION_FOOTER",LEP_SYS_TELEMETRY_LOCATION_E_TAG::LEP_TELEMETRY_LOCATION_FOOTER)
        .value("LEP_END_TELEMETRY_LOCATION",LEP_SYS_TELEMETRY_LOCATION_E_TAG::LEP_END_TELEMETRY_LOCATION)
        .export_values();

    py::enum_<LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG>(handle,"LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG")
        .value("LEP_SYS_FA_DIV_1",LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG::LEP_SYS_FA_DIV_1)
        .value("LEP_SYS_FA_DIV_2",LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG::LEP_SYS_FA_DIV_2)
        .value("LEP_SYS_FA_DIV_4",LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG::LEP_SYS_FA_DIV_4)
        .value("LEP_SYS_FA_DIV_8",LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG::LEP_SYS_FA_DIV_8)
        .value("LEP_SYS_FA_DIV_16",LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG::LEP_SYS_FA_DIV_16)
        .value("LEP_SYS_FA_DIV_32",LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG::LEP_SYS_FA_DIV_32)
        .value("LEP_SYS_FA_DIV_64",LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG::LEP_SYS_FA_DIV_64)
        .value("LEP_SYS_FA_DIV_128",LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG::LEP_SYS_FA_DIV_128)
        .value("LEP_SYS_END_FA_DIV",LEP_SYS_FRAME_AVERAGE_DIVISOR_E_TAG::LEP_SYS_END_FA_DIV)
        .export_values();

    py::class_<LEP_SYS_SCENE_STATISTICS_T_TAG>(handle,"LEP_SYS_SCENE_STATISTICS_T_TAG")
        .def(py::init<>())
        .def_readwrite("meanIntensity", &LEP_SYS_SCENE_STATISTICS_T_TAG::meanIntensity)
        .def_readwrite("maxIntensity", &LEP_SYS_SCENE_STATISTICS_T_TAG::maxIntensity)
        .def_readwrite("minIntensity", &LEP_SYS_SCENE_STATISTICS_T_TAG::minIntensity)
        .def_readwrite("numPixels", &LEP_SYS_SCENE_STATISTICS_T_TAG::numPixels);

    py::class_<LEP_SYS_BAD_PIXEL_T_TAG>(handle,"LEP_SYS_BAD_PIXEL_T_TAG")
        .def(py::init<>())
        .def_readwrite("row", &LEP_SYS_BAD_PIXEL_T_TAG::row)
        .def_readwrite("col", &LEP_SYS_BAD_PIXEL_T_TAG::col)
        .def_readwrite("value", &LEP_SYS_BAD_PIXEL_T_TAG::value)
        .def_readwrite("value2", &LEP_SYS_BAD_PIXEL_T_TAG::value2);

    py::class_<LEP_SYS_VIDEO_ROI_T_TAG>(handle,"LEP_SYS_VIDEO_ROI_T_TAG")
        .def(py::init<>())
        .def_readwrite("row", &LEP_SYS_VIDEO_ROI_T_TAG::startCol)
        .def_readwrite("row", &LEP_SYS_VIDEO_ROI_T_TAG::startRow)
        .def_readwrite("row", &LEP_SYS_VIDEO_ROI_T_TAG::endCol)
        .def_readwrite("row", &LEP_SYS_VIDEO_ROI_T_TAG::endRow);

    py::enum_<LEP_SYS_ENABLE_E_TAG>(handle,"LEP_SYS_ENABLE_E_TAG")
        .value("LEP_SYS_DISABLE",LEP_SYS_ENABLE_E_TAG::LEP_SYS_DISABLE)
        .value("LEP_SYS_ENABLE",LEP_SYS_ENABLE_E_TAG::LEP_SYS_ENABLE)
        .value("LEP_END_SYS_ENABLE",LEP_SYS_ENABLE_E_TAG::LEP_END_SYS_ENABLE)
        .export_values();

    py::enum_<LEP_SYS_SHUTTER_POSITION_E_TAG>(handle,"LEP_SYS_SHUTTER_POSITION_E_TAG")
        .value("LEP_SYS_SHUTTER_POSITION_UNKNOWN",LEP_SYS_SHUTTER_POSITION_E_TAG::LEP_SYS_SHUTTER_POSITION_UNKNOWN)
        .value("LEP_SYS_SHUTTER_POSITION_IDLE",LEP_SYS_SHUTTER_POSITION_E_TAG::LEP_SYS_SHUTTER_POSITION_IDLE)
        .value("LEP_SYS_SHUTTER_POSITION_OPEN",LEP_SYS_SHUTTER_POSITION_E_TAG::LEP_SYS_SHUTTER_POSITION_OPEN)
        .value("LEP_SYS_SHUTTER_POSITION_CLOSED",LEP_SYS_SHUTTER_POSITION_E_TAG::LEP_SYS_SHUTTER_POSITION_CLOSED)
        .value("LEP_SYS_SHUTTER_POSITION_BRAKE_ON",LEP_SYS_SHUTTER_POSITION_E_TAG::LEP_SYS_SHUTTER_POSITION_BRAKE_ON)
        .value("LEP_SYS_SHUTTER_POSITION_END",LEP_SYS_SHUTTER_POSITION_E_TAG::LEP_SYS_SHUTTER_POSITION_END)
        .export_values();

    py::enum_<LEP_SYS_FFC_SHUTTER_MODE_E_TAG>(handle,"LEP_SYS_FFC_SHUTTER_MODE_E_TAG")
        .value("LEP_SYS_SHUTTER_POSITION_UNKNOWN",LEP_SYS_FFC_SHUTTER_MODE_E_TAG::LEP_SYS_FFC_SHUTTER_MODE_MANUAL)
        .value("LEP_SYS_FFC_SHUTTER_MODE_AUTO",LEP_SYS_FFC_SHUTTER_MODE_E_TAG::LEP_SYS_FFC_SHUTTER_MODE_AUTO)
        .value("LEP_SYS_FFC_SHUTTER_MODE_EXTERNAL",LEP_SYS_FFC_SHUTTER_MODE_E_TAG::LEP_SYS_FFC_SHUTTER_MODE_EXTERNAL)
        .value("LEP_SYS_FFC_SHUTTER_MODE_END",LEP_SYS_FFC_SHUTTER_MODE_E_TAG::LEP_SYS_FFC_SHUTTER_MODE_END)
        .export_values();

    py::enum_<LEP_SYS_SHUTTER_TEMP_LOCKOUT_STATE_E_TAG>(handle,"LEP_SYS_SHUTTER_TEMP_LOCKOUT_STATE_E_TAG")
        .value("LEP_SYS_SHUTTER_LOCKOUT_INACTIVE",LEP_SYS_SHUTTER_TEMP_LOCKOUT_STATE_E_TAG::LEP_SYS_SHUTTER_LOCKOUT_INACTIVE)
        .value("LEP_SYS_SHUTTER_LOCKOUT_HIGH",LEP_SYS_SHUTTER_TEMP_LOCKOUT_STATE_E_TAG::LEP_SYS_SHUTTER_LOCKOUT_HIGH)
        .value("LEP_SYS_SHUTTER_POSITION_UNKNOWN",LEP_SYS_SHUTTER_TEMP_LOCKOUT_STATE_E_TAG::LEP_SYS_SHUTTER_LOCKOUT_LOW)
        .export_values();

    py::class_<LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG>(handle,"LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG")
        .def(py::init<>())
        .def_readwrite("shutterMode",&LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG::shutterMode)
        .def_readwrite("tempLockoutState",&LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG::tempLockoutState)
        .def_readwrite("videoFreezeDuringFFC",&LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG::videoFreezeDuringFFC)
        .def_readwrite("ffcDesired",&LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG::ffcDesired)
        .def_readwrite("elapsedTimeSinceLastFfc",&LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG::elapsedTimeSinceLastFfc)
        .def_readwrite("desiredFfcPeriod",&LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG::desiredFfcPeriod)
        .def_readwrite("explicitCmdToOpen",&LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG::explicitCmdToOpen)
        .def_readwrite("desiredFfcTempDelta",&LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG::desiredFfcTempDelta)
        .def_readwrite("imminentDelay",&LEP_SYS_FFC_SHUTTER_MODE_OBJ_T_TAG::imminentDelay);

    py::enum_<LEP_SYS_STATUS_E>(handle,"LEP_SYS_STATUS_E")
        .value("LEP_SYS_STATUS_WRITE_ERROR",LEP_SYS_STATUS_E::LEP_SYS_STATUS_WRITE_ERROR)
        .value("LEP_SYS_STATUS_ERROR",LEP_SYS_STATUS_E::LEP_SYS_STATUS_ERROR)
        .value("LEP_SYS_STATUS_READY",LEP_SYS_STATUS_E::LEP_SYS_STATUS_READY)
        .value("LEP_SYS_STATUS_BUSY",LEP_SYS_STATUS_E::LEP_SYS_STATUS_BUSY)
        .value("LEP_SYS_FRAME_AVERAGE_COLLECTING_FRAMES",LEP_SYS_STATUS_E::LEP_SYS_FRAME_AVERAGE_COLLECTING_FRAMES)
        .value("LEP_SYS_STATUS_END",LEP_SYS_STATUS_E::LEP_SYS_STATUS_END)
        .export_values();

    handle.def("LEP_RunSysPing",&LEP_RunSysPing);
    handle.def("LEP_GetSysStatus",&LEP_GetSysStatus);
    handle.def("LEP_GetSysFlirSerialNumber",&LEP_GetSysFlirSerialNumber);
    handle.def("LEP_GetSysCustSerialNumber",&LEP_GetSysCustSerialNumber);
    handle.def("LEP_GetSysCameraUpTime",&LEP_GetSysCameraUpTime);
    handle.def("LEP_GetSysAuxTemperatureCelcius",&LEP_GetSysAuxTemperatureCelcius);
    handle.def("LEP_GetSysFpaTemperatureCelcius",&LEP_GetSysFpaTemperatureCelcius);
    handle.def("LEP_GetSysAuxTemperatureKelvin",&LEP_GetSysAuxTemperatureKelvin);
    handle.def("LEP_GetSysFpaTemperatureKelvin",&LEP_GetSysFpaTemperatureKelvin);
    handle.def("LEP_GetSysTelemetryEnableState",&LEP_GetSysTelemetryEnableState);
    handle.def("LEP_SetSysTelemetryEnableState",&LEP_SetSysTelemetryEnableState);
    handle.def("LEP_GetSysTelemetryLocation",&LEP_GetSysTelemetryLocation);
    handle.def("LEP_SetSysTelemetryLocation",&LEP_SetSysTelemetryLocation);
    handle.def("LEP_RunSysAverageFrames",&LEP_RunSysAverageFrames);
    handle.def("LEP_GetSysFramesToAverage",&LEP_GetSysFramesToAverage);
    handle.def("LEP_SetSysFramesToAverage",&LEP_SetSysFramesToAverage);
    handle.def("LEP_GetSysSceneStatistics",&LEP_GetSysSceneStatistics);
    handle.def("LEP_RunFrameAverage",&LEP_RunFrameAverage);
    handle.def("LEP_GetSysSceneRoi",&LEP_GetSysSceneRoi);
    handle.def("LEP_SetSysSceneRoi",&LEP_SetSysSceneRoi);
    handle.def("LEP_GetSysThermalShutdownCount",&LEP_GetSysThermalShutdownCount);
    handle.def("LEP_GetSysShutterPosition",&LEP_GetSysShutterPosition);
    handle.def("LEP_SetSysShutterPosition",&LEP_SetSysShutterPosition);
    handle.def("LEP_GetSysFfcShutterModeObj",&LEP_GetSysFfcShutterModeObj);
    handle.def("LEP_SetSysFfcShutterModeObj",&LEP_SetSysFfcShutterModeObj);
    handle.def("LEP_GetSysFFCStatus",&LEP_GetSysFFCStatus);
    handle.def("LEP_RunSysFFCNormalization",&LEP_RunSysFFCNormalization);
}