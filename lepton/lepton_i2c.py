from lib import lepton_sdk, lepton_sys, lepton_oem, lepton_type

class LeptonI2c :
    def __init__(self):
        self._connected = False
        self._port = lepton_type.LEP_CAMERA_PORT_DESC_T()

    def lepton_connect(self) -> int :
        lepton_sdk.LEP_OpenPort(1, lepton_type.LEP_CAMERA_PORT_E.LEP_CCI_TWI, 400, self._port)
        self._connected = True
        return 0

    def lepton_perform_ffc(self) -> None :
        if(not self._connected):
            self.lepton_connect()
        lepton_sys.LEP_RunSysFFCNormalization(self._port)

    def lepton_reboot(self) -> None:
        if(not self._connected):
            self.lepton_connect()
        lepton_oem.LEP_RunOemReboot(self._port)