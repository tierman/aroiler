#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
#include "menu/menu.hpp"
#include "menu/menuItem.hpp"

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Ustawienie adresu ukladu na 0x27

int voltageAddress = 0;
int oilAddress = voltageAddress + sizeof(float);
int openTimeAddress = oilAddress + sizeof(int);
int delayTimeAddress = openTimeAddress + sizeof(int);
int voltageBaseAddress = delayTimeAddress + sizeof(int);
int menuModeAddress = voltageBaseAddress + sizeof(int);

float voltage = 0.00;
int oil = 0;
boolean menuMode = false;
int currentMenuPosition = 0;

// digital pins
const int BTN_RESET_PIN = 2;
const int BTN_NEXT_PIN = 3;
const int BTN_PREV_PIN = 4;
const int BTN_MENU_PIN = 5;
const int RELAY_PIN = 11;

// analog pins
const int voltageReadPin = A0;

const long interval_500 = 500;
const long interval_1000 = 1000;
unsigned long previousMillis = 0;
unsigned long previousMillisaa = 0;
const int maxOilLevel = 8;
const int voltageDisplayStartPosition = 9;

byte Drop[] = {
		B00000,
		B00100,
		B01110,
		B11111,
		B11111,
		B11111,
		B01110,
		B00000
};

typedef enum {
	BTN_MENU, BTN_RESET, BTN_PREV, BTN_NEXT, BTN_NONE
} BUTTONS;

BUTTONS prevPressedButton = BTN_NONE;

BUTTONS getPressedButton() {
	if (!digitalRead(BTN_MENU_PIN)) 	{return BTN_MENU;}
	if (!digitalRead(BTN_NEXT_PIN)) 	{return BTN_NEXT;}
	if (!digitalRead(BTN_PREV_PIN)) 	{return BTN_PREV;}
	if (!digitalRead(BTN_RESET_PIN)) 	{return BTN_RESET;}
	//default return none virtual button
	return BTN_NONE;
}

void increaseOilLevel() {
	int oilLevel = EEPROM.read(oilAddress) + 1;
	if(oilLevel >= maxOilLevel) {
		oilLevel = maxOilLevel;
	}
	EEPROM.put(oilAddress, oilLevel);
}

void decreaseOilLevel() {
	int oilLevel = EEPROM.read(oilAddress) - 1;
	if(oilLevel < 0) {
		oilLevel = 0;
	}
	EEPROM.put(oilAddress, oilLevel);
}

void clearOilLevel() {
	for (int i=0; i < maxOilLevel ; ++i) {
		lcd.setCursor(5+i, 1);
		lcd.print(" ");
	}
}

void printOilLevel(int oil) {
	for (int i=0; i < maxOilLevel ; ++i) {
		if (i < oil) {
			lcd.setCursor(5+i, 1);
			lcd.write(0);
		} else {
			lcd.setCursor(5+i, 1);
			lcd.print(" ");
		}
	}
}

void lcdBaseInfo() {
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Napiecie:      V");
	lcd.setCursor(0, 1);
	lcd.print("Olej:");
}

void lcdMenu() {

}

void lcdSetup() {
	lcd.init();
	lcd.begin(16, 2);
	lcd.backlight();
	lcd.createChar(0, Drop);
	lcdBaseInfo();
}

void menuSetup() {
	Menu menu;
	menu.addMenuPosition(openTimeAddress, "Czas otw.:");
	menu.addMenuPosition(delayTimeAddress, "Czas zam.:");
	menu.addMenuPosition(voltageBaseAddress, "Nap. wzorc.:");
}

void clearEeprom() {
	for (int i = 0; i < EEPROM.length(); i++) {
		EEPROM.write(i, 0);
	}
}

void readSavedData() {
	EEPROM.get(voltageAddress, voltage);
	oil = EEPROM.read(oilAddress);
}

void readVoltage() {
	float voltageValue = analogRead(voltageReadPin) * (4.72 / 1023.0);
	EEPROM.put(voltageAddress, voltageValue);
}

void resetButton() {
	if (!digitalRead(BTN_RESET_PIN)) {
		Serial.println("Reset button pressed");
		clearEeprom();
		lcdSetup();
		digitalWrite(BTN_RESET_PIN, HIGH);
	}
}

void printVoltage(float voltage) {
	lcd.setCursor(voltageDisplayStartPosition, 0);
	lcd.print(voltage);
}

void digitalPinSetup() {
	pinMode(BTN_RESET_PIN, INPUT_PULLUP);
	pinMode(BTN_MENU_PIN, INPUT_PULLUP);
	pinMode(BTN_NEXT_PIN, INPUT_PULLUP);
	pinMode(BTN_PREV_PIN, INPUT_PULLUP);
	pinMode(RELAY_PIN, OUTPUT);
	digitalWrite(RELAY_PIN, LOW);
}

void menuButton() {
	BUTTONS pressedButton = getPressedButton();
	if (pressedButton == BTN_MENU && prevPressedButton != pressedButton) {
		menuMode = !(boolean)EEPROM.read(menuModeAddress);
		EEPROM.write(menuModeAddress, (byte)menuMode);
		digitalWrite(BTN_MENU_PIN, HIGH);
		if (!menuMode) {
			lcdBaseInfo();
		}
		prevPressedButton = pressedButton;
	}
	if (pressedButton == BTN_NEXT && prevPressedButton != pressedButton && !(boolean)EEPROM.read(menuModeAddress)) {
		increaseOilLevel();
		prevPressedButton = pressedButton;
	}
	if (pressedButton == BTN_PREV && prevPressedButton != pressedButton && !(boolean)EEPROM.read(menuModeAddress)) {
		decreaseOilLevel();
		prevPressedButton = pressedButton;
	}
	if (pressedButton == BTN_NONE) {
		prevPressedButton = BTN_NONE;
	}
}

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	digitalPinSetup();
	readSavedData();
	lcdSetup();
	menuSetup();
}

void loop() {
	// put your main code here, to run repeatedly:
	unsigned long currentMillis = millis();

	resetButton();
	menuButton();

	if (menuMode) {
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Menu:");

	} else {

		if (currentMillis - previousMillis >= interval_500) {
			previousMillis = currentMillis;
			readVoltage();
			digitalWrite(RELAY_PIN, !digitalRead(RELAY_PIN));
			printVoltage(voltage);
		}

		printOilLevel(oil);

		if (currentMillis - previousMillisaa >= (interval_1000*3)) {
			previousMillisaa = currentMillis;
			//
			//clearOilLevel();
		}

		readSavedData();
	}
}

