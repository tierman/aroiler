#ifndef MENUITEM_HPP_
#define MENUITEM_HPP_
#include <Arduino.h>

class MenuItem {
	int eepromAddress;
	String name;
	MenuItem *before;
	MenuItem *after;

public:
	MenuItem(int eepromAddress, String name, MenuItem *before = NULL, MenuItem *after = NULL);
	~MenuItem();
	void addMenuPosition(int eepromAddress, String name);
	byte count();
	String getName(byte index);
};

#endif
