
from turtle import color
from typing import Iterable
import spidev

from .lib import lepton_sdk, lepton_type
from .lib import lepton_error_codes as lec
from .lib import lepton_sys as ls
from .lib import lepton_rad as lr
from .lib import lepton_oem as lo
from .lib import lepton_vid as lv
from .lib import lepton_agc as la
from .lepton_i2c import LeptonI2C
from ..utils.colormaps import ironblack,rainbow

import numpy as np

class LeptonSPI:
    SPI_CPHA   = 0x01                 # /* clock phase */
    SPI_CPOL   = 0x02                 # /* clock polarity */
    SPI_MODE_0 = (0|0)                # /* (original MicroWire) */ #(0,0) CPOL=0 (Clock Idle low level), CPHA=0 (SDO transmit/change edge active to idle)
    SPI_MODE_1 = (0|SPI_CPHA) #(0,1)  CPOL=0 (Clock Idle low level), CPHA=1 (SDO transmit/change edge idle to active)
    SPI_MODE_2 = (SPI_CPOL|0) #(1,0)  CPOL=1 (Clock Idle high level), CPHA=0 (SDO transmit/change edge active to idle)
    SPI_MODE_3 = (SPI_CPOL|SPI_CPHA) #(1,1)  CPOL=1 (Clock Idle high level), CPHA=1 (SDO transmit/change edge idle to active) 
    
    KELVIN  = -273.15
    FRAME_W = 80 #lepton 3 160
    FRAME_H = 60 #lepton 3 120

    __rgb_enabled = False
    __packet_count = 60
    __packet_size = 164
    __spidev = None

    def __init__(self,spi_bus = 0 ,spi_device  = 0, rgb = False):        
        self.open_port()
        self.set_vospi_data(LeptonI2C.get_instance())
        self.__rgb_enabled = rgb

    def init_setting(self ) -> None:
        self.__spidev.bits_per_word = 8
        self.__spidev.max_speed_hz = 20000000 # max 20MHz and min 2 MHz  based on datasheet
        self.__spidev.mode = self.SPI_MODE_3 # read page 46 lepton datasheet

    def open_port(self,spi_bus = 0 ,spi_device  = 0) :
        self.__spidev = spidev.SpiDev(spi_bus, spi_device)
        self.init_setting()

    def close_port(self) -> None:
        if(self.__spidev):
            self.__spidev.close()

    def read_packet(self) -> list:
        pass

    def read_frame(self):
        pass

    def resync(self):
        pass

    def get_last_frame_16(self):
        pass

    def get_last_frame_rgb(self):
        pass

    def raw_2_data16(self):
        pass

    def raw_2_rgb(self):
        pass

    def generate_colormap(self, colormap : str):
        chunk : Iterable

        def colormap_chunk(ulist, step):
            return map(lambda i: ulist[i: i + step], range(0, len(ulist), step))

        if colormap == "ironblack":
            chunk = colormap_chunk(ironblack,3)
        else :
            chunk = colormap_chunk(rainbow,3)

        lut = np.zeros((256, 1, 3), dtype=np.uint8)
        lut[:, 0, 0] = [chunk[0]] # blue
        lut[:, 0, 1] = [chunk[1]] # green
        lut[:, 0, 2] = [chunk[2]] # red
        return lut

    def set_vospi_data(self, i2c : LeptonI2C):
        # for more information about packet length etc read page 47 for lepton <= 2.5
        # and page 54 for lepton >= 3
        # check telemetry status
        self.__packet_count = 60 # default without telemetry
        if i2c.get_telemetry_status() :
            self.__packet_count = 63

        # check video format from lepton
        # always use raw14 bit format to get temperature
        # do coloring of greyscale image in python using raw_2_rgb
        if i2c.get_video_output_format() == lo.LEP_OEM_VIDEO_OUTPUT_FORMAT_TAG.LEP_VIDEO_OUTPUT_FORMAT_RGB888 :
            i2c.set_rgb_status(False)
