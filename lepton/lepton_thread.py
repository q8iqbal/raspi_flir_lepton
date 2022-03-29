
import typing
import lepton_color
from lepton_spi import LeptonSpi
from lepton_i2c import LeptonI2c
from PyQt5.QtCore import QThread,QObject,pyqtSignal, pyqtSlot
from PyQt5.QtGui import QImage


class LeptonThread(QThread):
    # read lepton engineering datashet for more information about packet size etc
    PACKET_SIZE = 164
    PACKET_SIZE_UINT16 = (PACKET_SIZE/2)
    PACKETS_PER_FRAME = 60
    FRAME_SIZE_UINT16 = (PACKET_SIZE_UINT16*PACKETS_PER_FRAME)
    FPS = 27

    update_text = pyqtSignal(str)
    update_img = pyqtSignal(QImage)

    def __init__(self, parent: typing.Optional[QObject] = ...) -> None:
        self.type_color_map = 3 # 1:colormap_rainbow  /  2:colormap_grayscale  /  3:colormap_ironblack(default)
        self.selected_color_map = lepton_color.COLORMAP_IRONBLACK

        self.lepton_type = 2 # 2:Lepton 2.x  / 3:Lepton 3.x
        self.img_width = 80
        self.img_height = 60

        self.spi_speed = 20 * 1000 * 1000; # SPI bus speed 20MHz
        self.spi_device = 0 # 0 or 1


        # min/max value for scaling
        self.auto_range_min = True
        self.auto_range_max = True
        self.range_min = 30000
        self.range_max = 32000

        self.lepton_spi = LeptonSpi()
        self.lepton_i2c = LeptonI2c()

        super().__init__(parent)

    def run(self) -> None:
        buffer_image = QImage(self.img_width, self.img_height, QImage.Format.Format_RGB888)
        self.lepton_spi.spi_open_port(self.spi_device, self.spi_speed)
        try:
            while True:
                self.update_img.emit(buffer_image)
        finally:
            self.lepton_spi.spi_close_port()

    def read_lepton_spi(self):
        self.lepton_spi.spi.read(self.PACKET_SIZE)
        pass
    
    def select_colormap(self, color_index : int) -> None:
        if(color_index == 1):
            self.type_color_map = 1
            self.selected_color_map = lepton_color.COLORMAP_RAINBOW
        elif(color_index == 2):
            self.type_color_map = 2
            self.selected_color_map = lepton_color.COLORMAP_GRAYSCALE
        else:
            self.type_color_map = 3
            self.selected_color_map = lepton_color.COLORMAP_IRONBLACK

    def select_lepton(self, lepton_version : int) -> None:
        if(lepton_version == 3):
            self.lepton_type = 3
            self.img_height = 120
            self.img_width = 160
        else:
            self.lepton_type = 2
            self.img_height = 60
            self.img_width = 800
    
    def select_spi_speed(self,speed : int) -> None:
        self.spi_speed = speed * 1000 * 1000

    def set_auto_scale(self) -> None:
        self.auto_range_max = True
        self.auto_range_min = True
    
    def use_range_min(self, range : int):
        self.auto_range_min = False
        self.range_min = range

    def use_range_max(self, range : int):
        self.auto_range_max = True
        self.range_max = range

    @pyqtSlot
    def perform_ffc(self):
        self.lepton_i2c.lepton_perform_ffc()