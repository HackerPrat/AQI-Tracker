# AQI Tracker

AQI Tracker is a project that lets you monitor the air quality in your environment by measuring the concentration of harmful gases like carbon dioxide, ammonia, and nitrogen oxides using the MQ135 air quality sensor. This fun little tool allows you to play around with different settings and see how they affect the air quality around you. With AQI Tracker, you can tinker with the air and discover new ways to keep it fresh and clean.


## Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software)
- [Adafruit_SSD1306 library](https://github.com/adafruit/Adafruit_SSD1306)

## Calibration

Before using the MQ135 sensor, it is important to calibrate it to get accurate readings. To calibrate the sensor, follow these steps:

1. Turn on the AQI Tracker device and let it warm up for at least 24 hours.
2. Take the device outside to an area with fresh air and record the value displayed on the OLED display. This value will be used as the "clean air" reference.
3. Move the device to the area you want to monitor and record the value displayed on the OLED display. This value will be used as the "dirty air" reference.
4. Use these two values to calculate a correction factor for the sensor. To do this, divide the "clean air" value by the "dirty air" value. This will give you a number between 0 and 1.
5. Multiply the sensor value displayed on the OLED display by the correction factor to get a more accurate reading.

## Wiring

| MQ135 Pin | ESP32 Pin |
|-----------|-----------|
| VCC       | 3.3V      |
| GND       | GND       |
| OUT       | ADC Pin (for example, GPIO34) |

| OLED Pin | ESP32 Pin (can also be labeled as) |
|---------|----------------------------------|
| VCC     | 3.3V                             |
| GND     | GND                              |
| SCL     | GPIO 22 (SCL)                    |
| SDA     | GPIO 21 (SDA)                    |

## Usage

1. Open the Arduino IDE and load the code onto your board.
2. Connect the MQ135 sensor and OLED display according to the wiring instructions.
3. Upload the code to your board.
4. Calibrate the MQ135 sensor by following the calibration instructions above.
5. Monitor the air quality displayed on the OLED display.

## Contributing

If you would like to contribute to this project, feel free to submit a pull request.
