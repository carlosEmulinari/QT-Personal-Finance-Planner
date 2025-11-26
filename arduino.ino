#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String inputString = "";

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Finance System");
  lcd.setCursor(0, 1);
  lcd.print("Waiting...");
}

void loop() {

  while (Serial.available()) {
    char c = Serial.read();

    // when a full command has been received
    if (c == '\n') {
      processCommand(inputString);
      inputString = "";   // reset buffer
    }
    else {
      inputString += c;
    }
  }
}

void processCommand(String cmd) {
  lcd.clear();

  // ---------- SAVINGS ----------
  if (cmd.startsWith("SAVE:")) {
    String value = cmd.substring(5);

    lcd.setCursor(0, 0);
    lcd.print("Saved Money:");

    lcd.setCursor(0, 1);
    lcd.print("$");
    lcd.print(value);

    return;
  }

  // ---------- INVESTMENTS ----------
  if (cmd.startsWith("INV:")) {
    String value = cmd.substring(4);

    lcd.setCursor(0, 0);
    lcd.print("Invested:");

    lcd.setCursor(0, 1);
    lcd.print("$");
    lcd.print(value);

    return;
  }

  // ---------- CONSULTANT ----------
  if (cmd.startsWith("CONS:")) {
    String name = cmd.substring(5);

    lcd.setCursor(0, 0);
    lcd.print("Consultant:");

    lcd.setCursor(0, 1);
    lcd.print(name);

    return;
  }

  // ---------- UNKNOWN ----------
  lcd.setCursor(0, 0);
  lcd.print("Unknown input");
}