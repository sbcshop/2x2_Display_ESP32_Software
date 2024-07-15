# 2x2_Display_ESP32_Software

<img src= "https://cdn.shopify.com/s/files/1/1217/2104/files/Main_ESP32_Banner.png?v=1720594391" />

The Quad Display Board features four displays in a single board Powered by ESP32 S3 WROOM-1, offering unparalleled flexibility and functionality for your creative endeavors. With options for both a 1.28" Round Display and a 1.54" Square Display, you have the freedom to choose the perfect size for your project needs. 

This Github provides getting started instruction for 2x2 Display with ESP32.

## Features:
- Powered by ESP32 S3 which is having Dual-core Arm Cortex-M0+ processor, running up to 133 MHz
- Four Square/Round Display in 2x2 arrangement for creative visual interactions
- Both Serial and Native USB available as Type C 
- DS3231 RTC for real-time capture and control activity With Backup Battery Holder
- BME280 Sensor for temperature, humidity and pressure monitoring
- Power and Charging LED for status indication
- Battery hookup and charging facilities for portability
- Onboard microSD card compatibility is useful for data logging purposes
- Multipurpose GPIOs breakout for additional peripheral interfacing
- Boot and Reset Buttons for programming purpose
- Two Programmable Buttons to add additional controls to project 
- Buzzer which helps to add audio alert for your project

## Specification:
- **Microcontroller**: [ESP32 S3 WROOM-1](https://github.com/sbcshop/2x2_Display_ESP32_Software/blob/main/Documents/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf), Xtensa® dual-core 32-bit LX7 microprocessor
- **Connectivity**: 2.4 GHz Wi-Fi (802.11 b/g/n) and Bluetooth® 5 (LE) 
- **Memory**: Flash up to 16 MB, PSRAM up to 8 MB
- **Supply Voltage**: 5V
- **Operating pin voltage**: 3.3V
- **Display**: 
- **Display Size**: 1.54” (Square), 1.28” (Round) 
- **Display Type**: IPS TFT 
- **Display Resolution**:  240 x 240 pixels
- **Display colors**: 65K RGB
- **Display interface**: SPI
- **Display Driver**: ST7789V (Square), GC9A01A (Round)
- **Sensor**: [BME280](https://github.com/sbcshop/2x2_Display_ESP32_Software/blob/main/Documents/BME280-Datasheet.pdf) for Temperature, Pressure & Relative Humidity
- **RTC Chip**: [DS3231SN](https://github.com/sbcshop/2x2_Display_ESP32_Software/blob/main/Documents/ds3231.pdf)
- **RTC Battery Holder**: Supports CR1220 3V Battery 
- **Operating Temperature Range**: -20°C ~ +70°C 

## Getting Started with 2x2 Display Powered by ESP32 
### Pinout
<img src= "https://cdn.shopify.com/s/files/1/1217/2104/files/ESP32_PINOUT.png?v=1720594472" />


### Interfacing Details

- **_Display interfacing with ESP32_**
	
  | ESP32 | Display | Function |
  |---|---|---|
  | IO12 | LCD1_CLK | Clock pin of SPI interface for Display|
  | IO11 | LCD1_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
  | IO9  | LCD1_CS | Chip Select pin of SPI interface|
  | IO13 | LCD1_DC| Data/Command (MISO) pin of SPI interface|
  | IO45 | LCD_BL | Backlight of display|
	
  | ESP32 | Display | Function |
  |---|---|---|
  | IO15 | LCD2_CLK | Clock pin of SPI interface for Display|
  | IO6  | LCD2_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
  | IO21 | LCD2_CS | Chip Select pin of SPI interface|
  | IO7  | LCD2_DC| Data/Command (MISO) pin of SPI interface|
  | IO45 | LCD_BL | Backlight of display|
	
  | ESP32 | Display | Function |
  |---|---|---|
  | IO14 | LCD3_CLK | Clock pin of SPI interface for Display|
  | IO8  | LCD3_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
  | IO48 | LCD3_CS | Chip Select pin of SPI interface|
  | IO47 | LCD3_DC| Data/Command (MISO) pin of SPI interface|
  | IO45 | LCD_BL | Backlight of display|
	
	| ESP32 | Display | Function |
  |---|---|---|
  | IO18 | LCD4_CLK | Clock pin of SPI interface for Display|
  | IO16 | LCD4_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
  | IO10 | LCD4_CS | Chip Select pin of SPI interface|
  | IO17 | LCD4_DC| Data/Command (MISO) pin of SPI interface|
  | IO45 | LCD_BL | Backlight of display|
	
 - **_Type C UART Serial USB Interface_**
     | ESP32 | USB To TTL (Serial) | Description | 
     |---|---|---|
     | TXD0/IO43 | RXD | UART communication pin |
     | RXD0/IO44 | TXD | UART communication pin |
	 

 - **_Type C Native USB Interface_**
     | ESP32 | Native USB | Description | 
     |---|---|---|
     | IO19 | D- | USB Communication pin |
     | IO20 | D+ | USB Communication pin |
	 
  
- **_BME280 & DS3231 RTC I2C Interfacing_**
    | ESP32 | Hardware | Hardware | Function |
    |---|---|---|---|
    |IO39 | BME280_SCL | RTC_SCL | I2C Serial Clock |
    |IO38 | BME280_SDA  | RTC_SDA | I2C Data pin |
  
- **_Buttons & Buzzer Interfacing_**
    | ESP32 | Hardware | Function |
    |---|---|---|
    |IO0 | BOOT |Boot button |
    |IO4 | BT1 | Programmable Button |
    |IO5 | BT2 | Programmable Button |
	|IO40 | Buzzer | Buzzer control pin |
	
  
- **_GPIOs Breakout_**
  
  | ESP32 | Type* | Multi-Function (_**Bold-Italic**_ default Function) |
  |---|---|---|
  |3V3  | P     | Positive Supply, 3.3V |
  |IO3  | I/O/T | RTC_GPIO3, _**GPIO3**_, TOUCH3, ADC1_CH2  |
  |IO46 | I/O/T | _**GPIO46**_ |  
  |GND  | P     | Supply Ground |
  
  *I-INPUT, O-OUTPUT, P-POWER & T-HIGH IMPEDENCE


## Resources
  * [Schematic](https://github.com/sbcshop/2x2_Display_ESP32_Hardware/blob/main/Design%20Data/SCH%202x2%20Display%20ESP32.pdf)
  * [Hardware Files](https://github.com/sbcshop/2x2_Display_ESP32_Hardware)
  * [Step File](https://github.com/sbcshop/2x2_Display_ESP32_Hardware/blob/main/Mechanical%20Data/2x2%20Display%20ESP32.step)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 Datasheet](https://github.com/sbcshop/2x2_Display_ESP32_Software/blob/main/Documents/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf)
  * [Arduino IDE 1 overview](https://docs.arduino.cc/software/ide-v1/tutorials/Environment)
    
## Related Products  
  * [2x2 Display with Pico W (Round)](https://shop.sb-components.co.uk/products/2x2-quad-display-board?variant=41538301427795)

    ![2x2 Display with Pico W (Round)](https://shop.sb-components.co.uk/cdn/shop/files/mainroundpico.png?v=1720526791&width=300)
  
  * [2x2 Display with Pico W (Square)](https://shop.sb-components.co.uk/products/2x2-quad-display-board?variant=41538301460563)

    ![2x2 Display with Pico W (Square)](https://shop.sb-components.co.uk/cdn/shop/files/squarepico.png?v=1720527004&width=300)
    
  * [Touchsy - 3.2" Touch LCD Display Based on ESP32](https://shop.sb-components.co.uk/products/touchsy-3-2-touch-lcd-display-based-on-esp32-mcu?variant=40828141174867)

    ![Touchsy - 3.2" Touch LCD Display Based on ESP32](https://shop.sb-components.co.uk/cdn/shop/files/esp.jpg?v=1686900424&width=300)
  
  * [Rotary Encoder - LED Array & Touch LCD Powered by ESP32](https://shop.sb-components.co.uk/products/rotary-encoder-led-array-touch-lcd-for-esp32-pico-hat?variant=41002601709651)

    ![Rotary Encoder - LED Array & Touch LCD Powered by ESP32](https://shop.sb-components.co.uk/cdn/shop/files/RotaryEncoder-LEDArray_TouchLCDforESP32PicoHAT_6.png?v=1710413189&width=300)


## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>
