#include "menuItem.hpp"
#include <Arduino.h>

MenuItem::MenuItem(int eepromAddress, String name, MenuItem *before = NULL, MenuItem *after = NULL)
		: eepromAddress(eepromAddress), name(name), before(before), after(after) {};

MenuItem::~MenuItem() {
		if (after) {
			delete after;
		}
	};

void MenuItem::addMenuPosition(int eepromAddress, String name) {
	if (after) {
		after -> addMenuPosition(eepromAddress, name);
	} else {
		after = new MenuItem(eepromAddress, name, this);
	}
};

byte MenuItem::count() {
	if (after) {
		return 1 + after -> count();
	}
		return 1;
};

String MenuItem::getName(byte index) {
		if (index && after) {
			return after -> getName(index -1);
		}
		return name;
};


