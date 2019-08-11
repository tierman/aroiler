#include "menu.hpp"
#include "menuItem.hpp"
#include <string.h>

Menu::Menu() : items(NULL), menuPosition(0) {};
Menu::~Menu() {
		delete items;
	};

void Menu::addMenuPosition(int eepromAddress, String name) {
		if (items) {
			items -> addMenuPosition(eepromAddress, name);
		} else {
			items = new MenuItem(eepromAddress, name);
		}
	};

void Menu::setMenuPosition(byte newMenuPosition) {
		if (this -> menuPosition != newMenuPosition) {
			this -> menuPosition = newMenuPosition;
		}
	};
