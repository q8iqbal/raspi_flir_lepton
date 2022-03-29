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

#include "../sdk/LEPTON_OEM.h"

namespace py = pybind11;

PYBIND11_MODULE(lepton_oem, handle){
    handle.doc() = "Contains OEM Interfaces";

    handle.attr("LEP_OEM_MODULE_BASE") = LEP_OEM_MODULE_BASE;
    handle.attr("LEP_CID_OEM_POWER_DOWN") = LEP_CID_OEM_POWER_DOWN;
    handle.attr("LEP_CID_OEM_STANDBY") = LEP_CID_OEM_STANDBY;
    handle.attr("LEP_CID_OEM_LOW_POWER_MODE_1") = LEP_CID_OEM_LOW_POWER_MODE_1;
    handle.attr("LEP_CID_OEM_LOW_POWER_MODE_2") = LEP_CID_OEM_LOW_POWER_MODE_2;
    handle.attr("LEP_CID_OEM_BIT_TEST") = LEP_CID_OEM_BIT_TEST;
    handle.attr("LEP_CID_OEM_MASK_REVISION") = LEP_CID_OEM_MASK_REVISION;
    handle.attr("LEP_CID_OEM_FLIR_PART_NUMBER") = LEP_CID_OEM_FLIR_PART_NUMBER;
    handle.attr("LEP_CID_OEM_SOFTWARE_VERSION") = LEP_CID_OEM_SOFTWARE_VERSION;
    handle.attr("LEP_CID_OEM_VIDEO_OUTPUT_ENABLE") = LEP_CID_OEM_VIDEO_OUTPUT_ENABLE;
    handle.attr("LEP_CID_OEM_VIDEO_OUTPUT_FORMAT") = LEP_CID_OEM_VIDEO_OUTPUT_FORMAT;
    handle.attr("LEP_CID_OEM_VIDEO_OUTPUT_SOURCE") = LEP_CID_OEM_VIDEO_OUTPUT_SOURCE;
    handle.attr("LEP_CID_OEM_VIDEO_OUTPUT_CHANNEL") = LEP_CID_OEM_VIDEO_OUTPUT_CHANNEL;
    handle.attr("LEP_CID_OEM_VIDEO_GAMMA_ENABLE") = LEP_CID_OEM_VIDEO_GAMMA_ENABLE;
    handle.attr("LEP_CID_OEM_CUST_PART_NUMBER") = LEP_CID_OEM_CUST_PART_NUMBER;
    handle.attr("LEP_CID_OEM_VIDEO_OUTPUT_CONSTANT") = LEP_CID_OEM_VIDEO_OUTPUT_CONSTANT;
    handle.attr("LEP_CID_OEM_REBOOT") = LEP_CID_OEM_REBOOT;
    handle.attr("LEP_CID_OEM_FFC_NORMALIZATION_TARGET") = LEP_CID_OEM_FFC_NORMALIZATION_TARGET;
    handle.attr("LEP_CID_OEM_STATUS") = LEP_CID_OEM_STATUS;
    handle.attr("LEP_CID_OEM_SCENE_MEAN_VALUE") = LEP_CID_OEM_SCENE_MEAN_VALUE;
    handle.attr("LEP_CID_OEM_POWER_MODE") = LEP_CID_OEM_POWER_MODE;
    handle.attr("LEP_CID_OEM_GPIO_MODE_SELECT") = LEP_CID_OEM_GPIO_MODE_SELECT;
    handle.attr("LEP_CID_OEM_GPIO_VSYNC_PHASE_DELAY") = LEP_CID_OEM_GPIO_VSYNC_PHASE_DELAY;
    handle.attr("LEP_CID_OEM_USER_DEFAULTS") = LEP_CID_OEM_USER_DEFAULTS;
    handle.attr("LEP_CID_OEM_USER_DEFAULTS_RESTORE") = LEP_CID_OEM_USER_DEFAULTS_RESTORE;
    handle.attr("LEP_CID_OEM_SHUTTER_PROFILE_OBJ") = LEP_CID_OEM_SHUTTER_PROFILE_OBJ;
    handle.attr("LEP_CID_OEM_THERMAL_SHUTDOWN_ENABLE_STATE") = LEP_CID_OEM_THERMAL_SHUTDOWN_ENABLE_STATE;
    handle.attr("LEP_CID_OEM_BAD_PIXEL_REPLACE_CONTROL") = LEP_CID_OEM_BAD_PIXEL_REPLACE_CONTROL;
    handle.attr("LEP_CID_OEM_TEMPORAL_FILTER_CONTROL") = LEP_CID_OEM_TEMPORAL_FILTER_CONTROL;
    handle.attr("LEP_CID_OEM_COLUMN_NOISE_ESTIMATE_CONTROL") = LEP_CID_OEM_COLUMN_NOISE_ESTIMATE_CONTROL;
    handle.attr("LEP_CID_OEM_PIXEL_NOISE_ESTIMATE_CONTROL") = LEP_CID_OEM_PIXEL_NOISE_ESTIMATE_CONTROL;
    handle.attr("LEP_OEM_MAX_PART_NUMBER_CHAR_SIZE") = LEP_OEM_MAX_PART_NUMBER_CHAR_SIZE;

    py::class_<LEP_OEM_PART_NUMBER_T>(handle, "LEP_OEM_PART_NUMBER_T")
        .def(py::init<>())
        // .def_readwrite("value", &LEP_OEM_PART_NUMBER_T::value);
        .def_property("value", [](LEP_OEM_PART_NUMBER_T &p)->py::array {
            auto dtype = py::dtype(py::format_descriptor<LEP_CHAR8>::format());
            return py::array(dtype, { LEP_OEM_MAX_PART_NUMBER_CHAR_SIZE }, { sizeof(LEP_CHAR8) }, p.value, nullptr);
        }, [](LEP_OEM_PART_NUMBER_T& p) {});

    py::class_<LEP_OEM_SW_VERSION_T>(handle, "LEP_OEM_SW_VERSION_T")
        .def(py::init<>())
        .def_readwrite("gpp_major", &LEP_OEM_SW_VERSION_T::gpp_major)
        .def_readwrite("gpp_minor", &LEP_OEM_SW_VERSION_T::gpp_minor)
        .def_readwrite("gpp_build", &LEP_OEM_SW_VERSION_T::gpp_build)
        .def_readwrite("dsp_major", &LEP_OEM_SW_VERSION_T::dsp_major)
        .def_readwrite("dsp_minor", &LEP_OEM_SW_VERSION_T::dsp_minor)
        .def_readwrite("dsp_build", &LEP_OEM_SW_VERSION_T::dsp_build)
        .def_readwrite("reserved", &LEP_OEM_SW_VERSION_T::reserved);

    py::enum_<LEP_OEM_VIDEO_OUTPUT_ENABLE_E>(handle, "LEP_OEM_VIDEO_OUTPUT_ENABLE_E")
        .value("LEP_VIDEO_OUTPUT_DISABLE", LEP_OEM_VIDEO_OUTPUT_ENABLE_E::LEP_VIDEO_OUTPUT_DISABLE)
        .value("LEP_VIDEO_OUTPUT_ENABLE", LEP_OEM_VIDEO_OUTPUT_ENABLE_E::LEP_VIDEO_OUTPUT_ENABLE)
        .value("LEP_END_VIDEO_OUTPUT_ENABLE", LEP_OEM_VIDEO_OUTPUT_ENABLE_E::LEP_END_VIDEO_OUTPUT_ENABLE)
        .export_values();

    py::enum_<LEP_OEM_VIDEO_OUTPUT_FORMAT_E>(handle, "LEP_OEM_VIDEO_OUTPUT_FORMAT_E")
        .value("LEP_VIDEO_OUTPUT_FORMAT_RAW8", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RAW8)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RAW10", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RAW10)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RAW12", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RAW12)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RGB888", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RGB888)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RGB666", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RGB666)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RGB565", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RGB565)
        .value("LEP_VIDEO_OUTPUT_FORMAT_YUV422_8BIT", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_YUV422_8BIT)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RAW14", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RAW14)
        .value("LEP_VIDEO_OUTPUT_FORMAT_YUV422_10BIT", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_YUV422_10BIT)
        .value("LEP_VIDEO_OUTPUT_FORMAT_USER_DEFINED", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_USER_DEFINED)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RAW8_2", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RAW8_2)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RAW8_3", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RAW8_3)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RAW8_4", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RAW8_4)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RAW8_5", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RAW8_5)
        .value("LEP_VIDEO_OUTPUT_FORMAT_RAW8_6", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_VIDEO_OUTPUT_FORMAT_RAW8_6)
        .value("LEP_END_VIDEO_OUTPUT_FORMAT", LEP_OEM_VIDEO_OUTPUT_FORMAT_E::LEP_END_VIDEO_OUTPUT_FORMAT)
        .export_values();

    py::enum_<LEP_OEM_VIDEO_OUTPUT_SOURCE_E>(handle, "LEP_OEM_VIDEO_OUTPUT_SOURCE_E")
        .value("LEP_VIDEO_OUTPUT_SOURCE_RAW", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_RAW)
        .value("LEP_VIDEO_OUTPUT_SOURCE_COOKED", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_COOKED)
        .value("LEP_VIDEO_OUTPUT_SOURCE_RAMP", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_RAMP)
        .value("LEP_VIDEO_OUTPUT_SOURCE_CONSTANT", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_CONSTANT)
        .value("LEP_VIDEO_OUTPUT_SOURCE_RAMP_H", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_RAMP_H)
        .value("LEP_VIDEO_OUTPUT_SOURCE_RAMP_V", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_RAMP_V)
        .value("LEP_VIDEO_OUTPUT_SOURCE_RAMP_CUSTOM", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_RAMP_CUSTOM)
        .value("LEP_VIDEO_OUTPUT_SOURCE_FRAME_CAPTURE", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_FRAME_CAPTURE)
        .value("LEP_VIDEO_OUTPUT_SOURCE_FRAME_FREEZE", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_FRAME_FREEZE)
        .value("LEP_VIDEO_OUTPUT_SOURCE_FRAME_0", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_FRAME_0)
        .value("LEP_VIDEO_OUTPUT_SOURCE_FRAME_1", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_FRAME_1)
        .value("LEP_VIDEO_OUTPUT_SOURCE_FRAME_2", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_FRAME_2)
        .value("LEP_VIDEO_OUTPUT_SOURCE_FRAME_3", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_FRAME_3)
        .value("LEP_VIDEO_OUTPUT_SOURCE_FRAME_4", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_VIDEO_OUTPUT_SOURCE_FRAME_4)
        .value("LEP_END_VIDEO_OUTPUT_SOURCE", LEP_OEM_VIDEO_OUTPUT_SOURCE_E::LEP_END_VIDEO_OUTPUT_SOURCE)
        .export_values();

    py::enum_<LEP_OEM_VIDEO_OUTPUT_CHANNEL_E>(handle, "LEP_OEM_VIDEO_OUTPUT_CHANNEL_E")
        .value("LEP_VIDEO_OUTPUT_CHANNEL_MIPI", LEP_OEM_VIDEO_OUTPUT_CHANNEL_E::LEP_VIDEO_OUTPUT_CHANNEL_MIPI)
        .value("LEP_VIDEO_OUTPUT_CHANNEL_VOSPI", LEP_OEM_VIDEO_OUTPUT_CHANNEL_E::LEP_VIDEO_OUTPUT_CHANNEL_VOSPI)
        .value("LEP_END_VIDEO_OUTPUT_CHANNEL", LEP_OEM_VIDEO_OUTPUT_CHANNEL_E::LEP_END_VIDEO_OUTPUT_CHANNEL)
        .export_values();

    py::enum_<LEP_OEM_VIDEO_GAMMA_ENABLE_E>(handle, "LEP_OEM_VIDEO_GAMMA_ENABLE_E")
        .value("LEP_VIDEO_GAMMA_DISABLE", LEP_OEM_VIDEO_GAMMA_ENABLE_E::LEP_VIDEO_GAMMA_DISABLE)
        .value("LEP_VIDEO_GAMMA_ENABLE", LEP_OEM_VIDEO_GAMMA_ENABLE_E::LEP_VIDEO_GAMMA_ENABLE)
        .value("LEP_END_VIDEO_GAMMA_ENABLE", LEP_OEM_VIDEO_GAMMA_ENABLE_E::LEP_END_VIDEO_GAMMA_ENABLE)
        .export_values();

    py::enum_<LEP_OEM_MEM_BUFFER_E>(handle, "LEP_OEM_MEM_BUFFER_E")
        .value("LEP_OEM_MEM_OTP_ODAC", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_ODAC)
        .value("LEP_OEM_MEM_OTP_GAIN", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_GAIN)
        .value("LEP_OEM_MEM_OTP_OFFSET_0", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_OFFSET_0)
        .value("LEP_OEM_MEM_OTP_OFFSET_1", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_OFFSET_1)
        .value("LEP_OEM_MEM_OTP_FFC", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_FFC)
        .value("LEP_OEM_MEM_OTP_LG0", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_LG0)
        .value("LEP_OEM_MEM_OTP_LG1", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_LG1)
        .value("LEP_OEM_MEM_OTP_LG2", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_LG2)
        .value("LEP_OEM_MEM_OTP_TFPA_LUT", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_TFPA_LUT)
        .value("LEP_OEM_MEM_OTP_TAUX_LUT", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_TAUX_LUT)
        .value("LEP_OEM_MEM_OTP_BAD_PIXEL_LIST", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_OTP_BAD_PIXEL_LIST)
        .value("LEP_OEM_MEM_SRAM_ODAC", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_SRAM_ODAC)
        .value("LEP_OEM_MEM_SRAM_BAD_PIXEL_LIST", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_SRAM_BAD_PIXEL_LIST)
        .value("LEP_OEM_MEM_SHARED_BUFFER_0", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_SHARED_BUFFER_0)
        .value("LEP_OEM_MEM_SHARED_BUFFER_1", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_SHARED_BUFFER_1)
        .value("LEP_OEM_MEM_SHARED_BUFFER_2", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_SHARED_BUFFER_2)
        .value("LEP_OEM_MEM_SHARED_BUFFER_3", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_SHARED_BUFFER_3)
        .value("LEP_OEM_MEM_SHARED_BUFFER_4", LEP_OEM_MEM_BUFFER_E::LEP_OEM_MEM_SHARED_BUFFER_4)
        .value("LEP_OEM_END_MEM_BUFFERS", LEP_OEM_MEM_BUFFER_E::LEP_OEM_END_MEM_BUFFERS)
        .export_values();

    py::enum_<LEP_OEM_STATUS_E>(handle, "LEP_OEM_STATUS_E")
        .value("LEP_OEM_STATUS_OTP_WRITE_ERROR", LEP_OEM_STATUS_E::LEP_OEM_STATUS_OTP_WRITE_ERROR)
        .value("LEP_OEM_STATUS_ERROR", LEP_OEM_STATUS_E::LEP_OEM_STATUS_ERROR)
        .value("LEP_OEM_STATUS_READY", LEP_OEM_STATUS_E::LEP_OEM_STATUS_READY)
        .value("LEP_OEM_STATUS_BUSY", LEP_OEM_STATUS_E::LEP_OEM_STATUS_BUSY)
        .value("LEP_OEM_FRAME_AVERAGE_COLLECTING_FRAMES", LEP_OEM_STATUS_E::LEP_OEM_FRAME_AVERAGE_COLLECTING_FRAMES)
        .value("LEP_OEM_STATUS_END", LEP_OEM_STATUS_E::LEP_OEM_STATUS_END)
        .export_values();

    py::enum_<LEP_OEM_STATE_E>(handle, "LEP_OEM_STATE_E")
        .value("LEP_OEM_DISABLE", LEP_OEM_STATE_E::LEP_OEM_DISABLE)
        .value("LEP_OEM_ENABLE", LEP_OEM_STATE_E::LEP_OEM_ENABLE)
        .value("LEP_OEM_END_STATE", LEP_OEM_STATE_E::LEP_OEM_END_STATE)
        .export_values();

    py::enum_<LEP_OEM_POWER_STATE_E>(handle, "LEP_OEM_POWER_STATE_E")
        .value("LEP_OEM_POWER_MODE_NORMAL", LEP_OEM_POWER_STATE_E::LEP_OEM_POWER_MODE_NORMAL)
        .value("LEP_OEM_POWER_MODE_LOW_POWER_1", LEP_OEM_POWER_STATE_E::LEP_OEM_POWER_MODE_LOW_POWER_1)
        .value("LEP_OEM_POWER_MODE_LOW_POWER_2", LEP_OEM_POWER_STATE_E::LEP_OEM_POWER_MODE_LOW_POWER_2)
        .value("LEP_OEM_END_POWER_MODE", LEP_OEM_POWER_STATE_E::LEP_OEM_END_POWER_MODE)
        .export_values();

    py::enum_<LEP_OEM_VSYNC_DELAY_E>(handle, "LEP_OEM_VSYNC_DELAY_E")
        .value("LEP_OEM_VSYNC_DELAY_MINUS_3", LEP_OEM_VSYNC_DELAY_E::LEP_OEM_VSYNC_DELAY_MINUS_3)
        .value("LEP_OEM_VSYNC_DELAY_MINUS_2", LEP_OEM_VSYNC_DELAY_E::LEP_OEM_VSYNC_DELAY_MINUS_2)
        .value("LEP_OEM_VSYNC_DELAY_MINUS_1", LEP_OEM_VSYNC_DELAY_E::LEP_OEM_VSYNC_DELAY_MINUS_1)
        .value("LEP_OEM_VSYNC_DELAY_NONE", LEP_OEM_VSYNC_DELAY_E::LEP_OEM_VSYNC_DELAY_NONE)
        .value("LEP_OEM_VSYNC_DELAY_PLUS_1", LEP_OEM_VSYNC_DELAY_E::LEP_OEM_VSYNC_DELAY_PLUS_1)
        .value("LEP_OEM_VSYNC_DELAY_PLUS_2", LEP_OEM_VSYNC_DELAY_E::LEP_OEM_VSYNC_DELAY_PLUS_2)
        .value("LEP_OEM_VSYNC_DELAY_PLUS_3", LEP_OEM_VSYNC_DELAY_E::LEP_OEM_VSYNC_DELAY_PLUS_3)
        .value("LEP_END_OEM_VSYNC_DELAY", LEP_OEM_VSYNC_DELAY_E::LEP_END_OEM_VSYNC_DELAY)
        .export_values();

    py::enum_<LEP_OEM_GPIO_MODE_E>(handle, "LEP_OEM_GPIO_MODE_E")
        .value("LEP_OEM_GPIO_MODE_GPIO", LEP_OEM_GPIO_MODE_E::LEP_OEM_GPIO_MODE_GPIO)
        .value("LEP_OEM_GPIO_MODE_I2C_MASTER", LEP_OEM_GPIO_MODE_E::LEP_OEM_GPIO_MODE_I2C_MASTER)
        .value("LEP_OEM_GPIO_MODE_SPI_MASTER_VLB_DATA", LEP_OEM_GPIO_MODE_E::LEP_OEM_GPIO_MODE_SPI_MASTER_VLB_DATA)
        .value("LEP_OEM_GPIO_MODE_SPIO_MASTER_REG_DATA", LEP_OEM_GPIO_MODE_E::LEP_OEM_GPIO_MODE_SPIO_MASTER_REG_DATA)
        .value("LEP_OEM_GPIO_MODE_SPI_SLAVE_VLB_DATA", LEP_OEM_GPIO_MODE_E::LEP_OEM_GPIO_MODE_SPI_SLAVE_VLB_DATA)
        .value("LEP_OEM_GPIO_MODE_VSYNC", LEP_OEM_GPIO_MODE_E::LEP_OEM_GPIO_MODE_VSYNC)
        .value("LEP_OEM_END_GPIO_MODE", LEP_OEM_GPIO_MODE_E::LEP_OEM_END_GPIO_MODE)
        .export_values();

    py::enum_<LEP_OEM_USER_PARAMS_STATE_E>(handle, "LEP_OEM_USER_PARAMS_STATE_E")
        .value("LEP_OEM_USER_PARAMS_STATE_NOT_WRITTEN", LEP_OEM_USER_PARAMS_STATE_E::LEP_OEM_USER_PARAMS_STATE_NOT_WRITTEN)
        .value("LEP_OEM_USER_PARAMS_STATE_NOT_WRITTEN", LEP_OEM_USER_PARAMS_STATE_E::LEP_OEM_USER_PARAMS_STATE_WRITTEN)
        .value("LEP_OEM_END_USER_PARAMS_STATE", LEP_OEM_USER_PARAMS_STATE_E::LEP_OEM_END_USER_PARAMS_STATE)
        .export_values();

    py::class_<LEP_OEM_SHUTTER_PROFILE_OBJ_T>(handle, "LEP_OEM_SHUTTER_PROFILE_OBJ_T")
        .def(py::init<>())
        .def_readwrite("closePeriodInFrames", &LEP_OEM_SHUTTER_PROFILE_OBJ_T::closePeriodInFrames)
        .def_readwrite("openPeriodInFrames", &LEP_OEM_SHUTTER_PROFILE_OBJ_T::openPeriodInFrames);

    py::class_<LEP_OEM_BAD_PIXEL_REPLACE_CONTROL_T>(handle, "LEP_OEM_BAD_PIXEL_REPLACE_CONTROL_T")
        .def(py::init<>())
        .def_readwrite("oemBadPixelReplaceEnable", &LEP_OEM_BAD_PIXEL_REPLACE_CONTROL_T::oemBadPixelReplaceEnable);

    py::class_<LEP_OEM_TEMPORAL_FILTER_CONTROL_T>(handle, "LEP_OEM_TEMPORAL_FILTER_CONTROL_T")
        .def(py::init<>())
        .def_readwrite("oemTemporalFilterEnable", &LEP_OEM_TEMPORAL_FILTER_CONTROL_T::oemTemporalFilterEnable);

    py::class_<LEP_OEM_COLUMN_NOISE_ESTIMATE_CONTROL_T>(handle, "LEP_OEM_COLUMN_NOISE_ESTIMATE_CONTROL_T")
        .def(py::init<>())
        .def_readwrite("oemColumnNoiseEstimateEnable", &LEP_OEM_COLUMN_NOISE_ESTIMATE_CONTROL_T::oemColumnNoiseEstimateEnable);

    py::class_<LEP_OEM_PIXEL_NOISE_SETTINGS_T>(handle, "LEP_OEM_PIXEL_NOISE_SETTINGS_T")
        .def(py::init<>())
        .def_readwrite("oemPixelNoiseEstimateEnable", &LEP_OEM_PIXEL_NOISE_SETTINGS_T::oemPixelNoiseEstimateEnable);

    py::class_<LEP_OEM_THERMAL_SHUTDOWN_ENABLE_T>(handle, "LEP_OEM_THERMAL_SHUTDOWN_ENABLE_T")
        .def(py::init<>())
        .def_readwrite("oemThermalShutdownEnable", &LEP_OEM_THERMAL_SHUTDOWN_ENABLE_T::oemThermalShutdownEnable);

    
    handle.def("LEP_RunOemPowerDown", &LEP_RunOemPowerDown);
    handle.def("LEP_RunOemPowerOn", &LEP_RunOemPowerOn);
    handle.def("LEP_RunOemStandby", &LEP_RunOemStandby);
    handle.def("LEP_RunOemReboot", &LEP_RunOemReboot);
    handle.def("LEP_RunOemLowPowerMode1", &LEP_RunOemLowPowerMode1);
    handle.def("LEP_RunOemLowPowerMode2", &LEP_RunOemLowPowerMode2);
    handle.def("LEP_RunOemBit", &LEP_RunOemBit);
    handle.def("LEP_GetOemMaskRevision", &LEP_GetOemMaskRevision);
    handle.def("LEP_GetOemFlirPartNumber", &LEP_GetOemFlirPartNumber);
    handle.def("LEP_GetOemCustPartNumber", &LEP_GetOemCustPartNumber);
    handle.def("LEP_GetOemSoftwareVersion", &LEP_GetOemSoftwareVersion);
    handle.def("LEP_GetOemVideoOutputEnable", &LEP_GetOemVideoOutputEnable);
    handle.def("LEP_SetOemVideoOutputEnable", &LEP_SetOemVideoOutputEnable);
    handle.def("LEP_GetOemVideoOutputFormat", &LEP_GetOemVideoOutputFormat);
    handle.def("LEP_SetOemVideoOutputFormat", &LEP_SetOemVideoOutputFormat);
    handle.def("LEP_GetOemVideoOutputSource", &LEP_GetOemVideoOutputSource);
    handle.def("LEP_SetOemVideoOutputSource", &LEP_SetOemVideoOutputSource);
    handle.def("LEP_GetOemVideoOutputSourceConstant", &LEP_GetOemVideoOutputSourceConstant);
    handle.def("LEP_SetOemVideoOutputSourceConstant", &LEP_SetOemVideoOutputSourceConstant);
    handle.def("LEP_GetOemVideoOutputChannel", &LEP_GetOemVideoOutputChannel);
    handle.def("LEP_SetOemVideoOutputChannel", &LEP_SetOemVideoOutputChannel);
    handle.def("LEP_GetOemVideoGammaEnable", &LEP_GetOemVideoGammaEnable);
    handle.def("LEP_SetOemVideoGammaEnable", &LEP_SetOemVideoGammaEnable);
    handle.def("LEP_GetOemCalStatus", &LEP_GetOemCalStatus);
    handle.def("LEP_GetOemFFCNormalizationTarget", &LEP_GetOemFFCNormalizationTarget);
    handle.def("LEP_SetOemFFCNormalizationTarget", &LEP_SetOemFFCNormalizationTarget);
    handle.def("LEP_RunOemFFCNormalization", &LEP_RunOemFFCNormalization);
    handle.def("LEP_GetOemFrameMean", &LEP_GetOemFrameMean);
    handle.def("LEP_GetOemPowerMode", &LEP_GetOemPowerMode);
    handle.def("LEP_SetOemPowerMode", &LEP_SetOemPowerMode);
    handle.def("LEP_RunOemFFC", &LEP_RunOemFFC);
    handle.def("LEP_GetOemGpioMode", &LEP_GetOemGpioMode);
    handle.def("LEP_SetOemGpioMode", &LEP_SetOemGpioMode);
    handle.def("LEP_GetOemGpioVsyncPhaseDelay", &LEP_GetOemGpioVsyncPhaseDelay);
    handle.def("LEP_SetOemGpioVsyncPhaseDelay", &LEP_SetOemGpioVsyncPhaseDelay);
    handle.def("LEP_GetOemUserDefaultsState", &LEP_GetOemUserDefaultsState);
    handle.def("LEP_RunOemUserDefaultsCopyToOtp", &LEP_RunOemUserDefaultsCopyToOtp);
    handle.def("LEP_RunOemUserDefaultsRestore", &LEP_RunOemUserDefaultsRestore);
    handle.def("LEP_GetOemThermalShutdownEnable", &LEP_GetOemThermalShutdownEnable);
    handle.def("LEP_SetOemThermalShutdownEnable", &LEP_SetOemThermalShutdownEnable);
    handle.def("LEP_GetOemShutterProfileObj", &LEP_GetOemShutterProfileObj);
    handle.def("LEP_SetOemShutterProfileObj", &LEP_SetOemShutterProfileObj);
    handle.def("LEP_GetOemBadPixelReplaceControl", &LEP_GetOemBadPixelReplaceControl);
    handle.def("LEP_SetOemBadPixelReplaceControl", &LEP_SetOemBadPixelReplaceControl);
    handle.def("LEP_GetOemTemporalFilterControl", &LEP_GetOemTemporalFilterControl);
    handle.def("LEP_SetOemTemporalFilterControl", &LEP_SetOemTemporalFilterControl);
    handle.def("LEP_GetOemColumnNoiseEstimateControl", &LEP_GetOemColumnNoiseEstimateControl);
    handle.def("LEP_SetOemColumnNoiseEstimateControl", &LEP_SetOemColumnNoiseEstimateControl);
    handle.def("LEP_GetOemPixelNoiseSettings", &LEP_GetOemPixelNoiseSettings);
    handle.def("LEP_SetOemPixelNoiseSettings", &LEP_SetOemPixelNoiseSettings);
}