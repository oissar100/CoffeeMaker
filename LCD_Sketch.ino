#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// Set the I2C pins
const int SDA_PIN = 23;
const int SCL_PIN = 22;

// Set LCD address, number of columns and rows
// If you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN);
  // Initialize LCD
  lcd.init();
  // Turn on LCD backlight
  lcd.backlight();
}

void loop() {
  // Set cursor to first column, first row
  lcd.setCursor(0, 0);
  // Print message
  lcd.print("Hello, World!");
  delay(1000);
  // Clears the display to print new message
  lcd.clear();
  // Set cursor to first column, second row
  lcd.setCursor(0, 1);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear();
}
