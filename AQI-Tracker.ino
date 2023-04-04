#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int OLED_ADDR = 0x3C;
const int OLED_WIDTH = 128; //Change this according to your display's WIDTH
const int OLED_HEIGHT = 64; //Change this according to your display's HEIGHT
const int MQ135_PIN = 34;

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void setup() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  int16_t x, y;
  uint16_t w, h;
  display.getTextBounds("Air Quality (PPM)", 0, 0, &x, &y, &w, &h);
  int airQualityX = (OLED_WIDTH / 2) - (w / 2);
  
  // Read the output from the MQ135 sensor
  int mq135Value = analogRead(MQ135_PIN);

  // Check for sensor error
  if (mq135Value < 0 || mq135Value > 4096) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Sensor Error!");
    display.display();
    delay(1000);
    return;
  }

  // Convert the analog value to a concentration in PPM (parts per million)
  // Also used for calibrating the sensor, comment out "* ((1000.0 / 4096) * <your coefficient>);" when testing.
  // I used 1.2 with mine but you will have to find out your sensor's coefficient yourself!
  float ppmConcentration = mq135Value* (500.0 / 4096); //remove the ";" and everything upto the comment ending(\\) once you have your <Coefficient Value>, remember to add another "(" before "(500.0 / 4096);"]\\ * <Coefficient Value>);

  // Display the concentration on the OLED display
  display.clearDisplay();
  display.setCursor(airQualityX, 20);
  display.print("Air Quality (PPM)");
  display.setCursor(airQualityX, 40);
  display.print(ppmConcentration);
  display.print(" PPM");
  display.display();

  delay(1000);
}
