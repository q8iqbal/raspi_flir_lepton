from .lib import lepton_sdk, lepton_type
from .lib import lepton_error_codes as lec
from .lib import lepton_sys as ls
from .lib import lepton_rad as lr
from .lib import lepton_oem as lo
from .lib import lepton_vid as lv
from .lib import lepton_agc as la
from ..utils.log_util import logger
from copy import copy

class LeptonI2C :
    _port : lepton_type.LEP_CAMERA_PORT_DESC_T_TAG
    _connected : bool
    __instance = None

    def __init__(self):
        if LeptonI2C.__instance != None :
            raise Exception("This is singleton class")
        else :
            self._connected = False
            self._port = lepton_type.LEP_CAMERA_PORT_DESC_T_TAG()
            LeptonI2C.__instance = self 

    @staticmethod
    def get_instance():
        if LeptonI2C.__instance == None:
            LeptonI2C()
        return LeptonI2C.__instance

    # def __init__(self):
    #     self._connected = False
    #     self._port = lepton_type.LEP_CAMERA_PORT_DESC_T_TAG()
    
    def _check_connection(self):
        logger.debug("checking i2c connections")
        if(not self._connected):
            if(not self.connect()):
                raise IOError("i2c port won't open")
        else:
            logger.debug("i2c already connected")
                
    def connect(self) -> bool :
        logger.debug("start connecting i2c")
        result = lepton_sdk.LEP_OpenPort(1, copy(lepton_type.LEP_CAMERA_PORT_E_TAG.LEP_CCI_TWI), 400, self._port)
        if(result == lec.Result.LEP_OK):
            self._connected = True
            logger.debug("i2c port connected")
        else:
            logger.critical("Failed to connect i2c port")
        logger.debug("connecting process finished")
        return self._connected

    def set_shutter_pos(self, position : ls.LEP_SYS_SHUTTER_POSITION_E_TAG):
        self._check_connection()

        logger.debug("start change shutter position")

        result = ls.LEP_SetSysShutterPosition(self._port, position)
        if(result != lec.Result.LEP_OK):
            logger.error("Cannot change shutter position")
            raise IOError("Shutter can't change position")

        logger.debug("finish change shutter position")

    def perform_ffc(self) -> None :
        self._check_connection()
        
        logger.debug("start performing ffc normalization")
        
        self.set_shutter_pos(ls.LEP_SYS_SHUTTER_POSITION_E_TAG.LEP_SYS_SHUTTER_POSITION_CLOSED)

        if(ls.LEP_RunSysFFCNormalization(self._port) != lec.Result.LEP_OK):
            logger.error("Can't perform ffc normalization")
            raise IOError("Can't perform ffc normalization")
        else:
            ffc_status = copy(ls.LEP_SYS_STATUS_E_TAG.LEP_SYS_STATUS_BUSY)
            while True:
                if(ls.LEP_GetSysFFCStatus(self._port, ffc_status) != lec.Result.LEP_OK):
                    logger.error("Can't get ffc status")
                    raise IOError("Can't get ffc status")
                if(ffc_status != ls.LEP_SYS_STATUS_E_TAG.LEP_SYS_STATUS_BUSY):
                    break
                
        self.set_shutter_pos(ls.LEP_SYS_SHUTTER_POSITION_E_TAG.LEP_SYS_SHUTTER_POSITION_OPEN)
        logger.debug("finish performing ffc normalization")

    
    def perform_rad_ffc(self)->None:
        self._check_connection()
        logger.debug("start performing radiometry ffc normalization")
        
        self.set_shutter_pos(ls.LEP_SYS_SHUTTER_POSITION_E_TAG.LEP_SYS_SHUTTER_POSITION_CLOSED)

        if(lr.LEP_RunRadFFC(self._port) != lec.Result.LEP_OK):
            logger.error("Can't perform radiometry ffc normalization")
            raise IOError("Can't perform radiometry ffc normalization")
        else:
            ffc_status = copy(ls.LEP_SYS_STATUS_E_TAG.LEP_SYS_STATUS_BUSY)
            while True:
                if(ls.LEP_GetSysFFCStatus(self._port, ffc_status) != lec.Result.LEP_OK):
                    logger.error("Can't get ffc status")
                    raise IOError("Can't get ffc status")
                if(ffc_status != ls.LEP_SYS_STATUS_E_TAG.LEP_SYS_STATUS_BUSY):
                    break

        self.set_shutter_pos(ls.LEP_SYS_SHUTTER_POSITION_E_TAG.LEP_SYS_SHUTTER_POSITION_OPEN)

        logger.debug("finish performing radiometry ffc normalization")


    def reset_camera(self):
        self._check_connection()
        logger.debug("Start resetting camera")

        if(lo.LEP_RunOemReboot(self._port) != lec.Result.LEP_OK):
            logger.error("Failed reset camera")
            raise IOError("Failed reset camera")

        logger.debug("done reseting")

    def power_off_camera(self):
        self._check_connection()
        if(lo.LEP_RunOemPowerDown(self._port) != lec.Result.LEP_OK):
            logger.error("Failed power off camera")
            raise IOError("Failed power off camera")

    def power_on_camera(self):
        self._check_connection()
        if(lo.LEP_RunOemPowerOn(self._port) != lec.Result.LEP_OK):
            logger.error("Failed power on camera")
            raise IOError("Failed power on camera")

    def reboot_camera(self):
        gain_mode = self.get_gain_mode()
        radiometry_status = self.get_radiometry_status()
        agc_status = self.get_agc_status()
        rgb_status = self.get_rgb_status()
        logger.debug("Temporary status saved")

        self.reset_camera()

        self.set_gain_mode(gain_mode)
        self.set_radiometry_status(radiometry_status)
        self.set_agc_status(agc_status)
        self.set_rgb_status(rgb_status)
        logger.debug("Temporary status restored")

        self.perform_ffc()


    # DON"T USE THIS FUNCTION
    # read engineering datasheet page 13
    # you need 5.9 voltage to do this
    # and you need to connect vprog pin on breakout board first
    def save_params(self):
        logger.debug("Saving camera parameter to OTP")
        self._check_connection()
        if lo.LEP_RunOemUserDefaultsCopyToOtp(self._port) != lec.Result.LEP_OK :
            logger.error("Can't save params to OTP")
            raise IOError("Can't save params to OTP")
        logger.debug("Camera parameter saved to OTP")

    # def load_params(self):
    #     self._check_connection()
    #     if lo.LEP_RunOemUserDefaultsCopyToOtp(self._port) != lec.Result.LEP_OK :
    #         logger.error("Can't load params to OTP")
    #         raise IOError("Can't load params to OTP")

    def get_sensor_temperature(self) -> float:
        self._check_connection()
        status, temp = ls.LEP_GetSysFpaTemperatureKelvin(self._port)
        if(status != lec.Result.LEP_OK) :
            logger.error("Can't read fpa temp")
            raise IOError("Can't read fpa temp")
        logger.debug(f"Fpa temp : {temp/100} °K")
        return temp/100
        
    def set_radiometry_status(self, status : bool):
        self._check_connection()
        if self.get_radiometry_status() != status :
            new_status = lr.LEP_RAD_ENABLE_E_TAG.LEP_RAD_ENABLE if status else lr.LEP_RAD_ENABLE_E_TAG.LEP_RAD_DISABLE
            if lr.LEP_SetRadEnableState(self._port, new_status) != lec.Result.LEP_OK :
                logger.error("Can't update radiometry status")
                raise IOError("Can't update radiometry status")

    def get_radiometry_status(self) -> bool:
        self._check_connection()
        status = copy(lr.LEP_RAD_ENABLE_E_TAG.LEP_RAD_DISABLE)
        if lr.LEP_GetRadEnableState(self._port, status) != lec.Result.LEP_OK :
            logger.error("Can't read radiometry status")
            raise IOError("Can't read radiometry status")

        if status == lr.LEP_RAD_ENABLE_E_TAG.LEP_RAD_ENABLE :
            return True
        else:
            return False

    def set_agc_status(self, status : bool):
        self._check_connection()
        if self.get_agc_status() != status :
            new_status = copy(lr.LEP_AGC_ENABLE_TAG.LEP_AGC_ENABLE) if status else copy(lr.LEP_AGC_ENABLE_TAG.LEP_AGC_DISABLE)
            if lr.LEP_SetAgcEnableState(self._port, new_status) != lec.Result.LEP_OK :
                logger.error("Can't update AGC status")
                raise IOError("Can't update AGC status")        

    def get_agc_status(self) -> bool:
        self._check_connection()
        status = copy(la.LEP_AGC_ENABLE_TAG.LEP_AGC_DISABLE)
        if la.LEP_GetAgcEnableState(self._port, status) != lec.Result.LEP_OK :
            logger.error("Can't read agc status")
            raise IOError("Can't read agc status")

        if status == la.LEP_AGC_ENABLE_TAG.LEP_AGC_ENABLE :
            return True
        else :
            return False

    def set_gain_mode(self, mode :ls.LEP_SYS_GAIN_MODE_E_TAG ):
        self._check_connection()
        if self.get_gain_mode() != mode:
            if ls.LEP_GetSysGainMode(self._port,mode) != lec.Result.LEP_OK :
                logger.error("Can't update gain mode")
                raise IOError("Can't update gain mode")

    def get_gain_mode(self) -> ls.LEP_SYS_GAIN_MODE_E_TAG:
        self._check_connection()
        mode = copy(ls.LEP_SYS_GAIN_MODE_E_TAG.LEP_SYS_GAIN_MODE_HIGH)
        if (ls.LEP_GetSysGainMode(self._port, mode) == lec.Result.LEP_OK):
            return mode
        else:
            logger.error("Failed to read gain mode")
            raise IOError("Failed to read gain mode")

    def set_telemetry_status(self, status : bool):
        self._check_connection()
        if self.get_telemetry_status() != status :
            new_status = copy(ls.LEP_SYS_TELEMETRY_ENABLE_STATE_E_TAG.LEP_TELEMETRY_ENABLED) if status else copy(ls.LEP_SYS_TELEMETRY_ENABLE_STATE_E_TAG.LEP_TELEMETRY_DISABLED)
            if ls.LEP_SetSysTelemetryEnableState(self._port, new_status) != lec.Result.LEP_OK :
                logger.error("Failed to update telemetry status")
                raise IOError("Failed to update telemetry status")

    def get_telemetry_status(self) -> bool:
        self._check_connection()
        status = copy(ls.LEP_SYS_TELEMETRY_ENABLE_STATE_E_TAG.LEP_TELEMETRY_DISABLED)
        result = ls.LEP_GetSysTelemetryEnableState(self._port, status)
        if(result != lec.Result.LEP_OK ):
            logger.error("Can't read telemetry status")
            raise IOError("Can't read telemetry status")
        
        if status == ls.LEP_SYS_TELEMETRY_ENABLE_STATE_E_TAG.LEP_TELEMETRY_ENABLED :
            return True
        else :
            return False

    def get_video_output_format(self) -> lo.LEP_OEM_VIDEO_OUTPUT_FORMAT_TAG:
        self._check_connection()
        format = copy(lo.LEP_OEM_VIDEO_OUTPUT_FORMAT_TAG.LEP_VIDEO_OUTPUT_FORMAT_RGB888)
        if lo.LEP_GetOemVideoOutputFormat(self._port, format ) != lec.Result.LEP_OK :
            logger.error("Can't read video output format")
            raise IOError("Can't read video output format")
        return format
    
    def get_rgb_status(self) -> bool:
        if self.get_video_output_format() == lo.LEP_OEM_VIDEO_OUTPUT_FORMAT_TAG.LEP_VIDEO_OUTPUT_FORMAT_RGB888 :
            return True
        else : 
            return False

    def set_rgb_status(self, status : bool = True):
        self._check_connection()
        if self.get_rgb_status() != status :
            new_format : lo.LEP_OEM_VIDEO_OUTPUT_FORMAT_TAG
            if status :
                # based on engineering datasheet
                # in order to enable rgb video format
                # you need to disable telemetry and enable agc
                # don't forget to set video color LUT
                self.set_telemetry_status(False)
                self.set_agc_status(True)
                self.set_vid_color_lut(lv.LEP_PCOLOR_LUT_E_TAG.LEP_VID_FUSION_LUT) # default color LUT
                new_format = copy(lo.LEP_OEM_VIDEO_OUTPUT_FORMAT_TAG.LEP_VIDEO_OUTPUT_FORMAT_RGB888)
            else : 
                new_format = copy(lo.LEP_OEM_VIDEO_OUTPUT_FORMAT_TAG.LEP_VIDEO_OUTPUT_FORMAT_RAW14)

            if lo.LEP_GetOemVideoOutputFormat(self._port, new_format) != lec.Result.LEP_OK :
                logger.error("Can't update video output format")
                raise IOError("Can't update video output format")

    def set_vid_color_lut(self, color : lv.LEP_PCOLOR_LUT_E_TAG ):
        self._check_connection()
        if self.get_vid_color_lut() != color:
            if lv.LEP_SetVidPcolorLut(self._port,color) != lec.Result.LEP_OK :
                logger.error("Can't update video color LUT mode")
                raise IOError("Can't update video color LUT mode")

    def get_vid_color_lut(self) -> lv.LEP_PCOLOR_LUT_E_TAG :
        self._check_connection()
        color = copy(lv.LEP_PCOLOR_LUT_E_TAG.LEP_VID_FUSION_LUT)
        if lv.LEP_GetVidPcolorLut(self._port, color) != lec.Result.LEP_OK :
            logger.error("Can't read video color LUT mode")
            raise IOError("Can't video color LUT mode")
        return color

    def set_spot_ROI(self,x:int,y:int,w:int,h:int):
        self._check_connection()
        roi = lr.LEP_RAD_ROI_T_TAG()
        roi.startCol = x
        roi.startRow = y
        roi.endCol = x+w
        roi.endRow = y+h

        if lr.LEP_SetRadSpotmeterRoi(self._port,roi) != lec.Result.LEP_OK :
            logger.error("Can't update spotmeter ROI")
            raise IOError("Can't update spotmeter ROI")

    def get_spot_ROI(self):
        self._check_connection()
        roi = lr.LEP_RAD_ROI_T_TAG()
        if lr.LEP_GetRadSpotmeterRoi(self._port,roi) != lec.Result.LEP_OK :
            logger.error("Can't read spotmeter ROI")
            raise IOError("Can't read spotmeter ROI")

        x : int = roi.startCol 
        y : int = roi.startRow
        w : int = roi.endCol - x
        h : int = roi.endRow - y
        return (x,y,w,h)

    def get_spot_info(self):
        self._check_connection()
        info = lr.LEP_RAD_SPOTMETER_OBJ_KELVIN_T_TAG()
        if lr.LEP_GetRadSpotmeterObjInKelvinX100(self._port,info) != lec.Result.LEP_OK :
            logger.error("Can't read spotmeter ROI")
            raise IOError("Can't read spotmeter ROI")

        valueK : float = info.radSpotmeterValue/100
        minK : float = info.radSpotmeterMinValue/100
        maxK : float = info.radSpotmeterMaxValue/100
        count : int = info.radSpotmeterPopulation

        return (valueK,minK,maxK,count)