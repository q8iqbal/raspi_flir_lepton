import spidev

class LeptonSpi:
    #----- SET SPI MODE -----
    SPI_MODE_0 = 0b00 #(0,0) CPOL=0 (Clock Idle low level), CPHA=0 (SDO transmit/change edge active to idle)
    SPI_MODE_1 = 0b01 #(0,1)  CPOL=0 (Clock Idle low level), CPHA=1 (SDO transmit/change edge idle to active)
    SPI_MODE_2 = 0b10 #(1,0)  CPOL=1 (Clock Idle high level), CPHA=0 (SDO transmit/change edge active to idle)
    SPI_MODE_3 = 0b11 #(1,1)  CPOL=1 (Clock Idle high level), CPHA=1 (SDO transmit/change edge idle to active)

    def __init__(self) -> None:
        self.spi = None    

    def spi_setting(self , spi_speed = 10000000) -> None:
        self.spi.bits_per_word = 8
        self.spi.max_speed_hz = spi_speed
        self.spi.mode = self.SPI_MODE_3

    def spi_open_port(self, spi_device : int, spi_speed : int) -> None:
        self.spi = spidev.SpiDev(0, spi_device)
        self.spi_setting(spi_speed)

    def spi_close_port(self) -> None:
        if(self.spi):
            self.spi.close()
