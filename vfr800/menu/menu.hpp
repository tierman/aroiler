#ifndef MENU_HPP_
#define MENU_HPP_
#include "menuItem.hpp"
#include <Arduino.h>

class Menu {
	MenuItem *items;
	byte menuPosition;

public:
	Menu();
	~Menu();

	void addMenuPosition(int eepromAddress, String name);
	void setMenuPosition(byte newMenuPosition);
};

#endif
