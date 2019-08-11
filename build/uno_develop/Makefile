ifeq ($(OS),Windows_NT)
SHELL = cmd
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/menu/menu.cpp.o \
	project/menu/menuItem.cpp.o \
	project/vfr800.cpp.o \

PLATFORM_CORE_OBJS = \
	core/HardwareSerial1.cpp.o \
	core/Tone.cpp.o \
	core/IPAddress.cpp.o \
	core/hooks.c.o \
	core/wiring_digital.c.o \
	core/wiring_shift.c.o \
	core/WString.cpp.o \
	core/HardwareSerial3.cpp.o \
	core/PluggableUSB.cpp.o \
	core/abi.cpp.o \
	core/WInterrupts.c.o \
	core/wiring.c.o \
	core/main.cpp.o \
	core/wiring_pulse.S.o \
	core/CDC.cpp.o \
	core/HardwareSerial0.cpp.o \
	core/HardwareSerial2.cpp.o \
	core/WMath.cpp.o \
	core/new.cpp.o \
	core/HardwareSerial.cpp.o \
	core/Stream.cpp.o \
	core/wiring_pulse.c.o \
	core/wiring_analog.c.o \
	core/USBCore.cpp.o \
	core/Print.cpp.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \
	libraries/LiquidCrystal_I2C/1.1.2/LiquidCrystal_I2C.cpp.o \
	libraries/Wire/src/utility/twi.c.o \
	libraries/Wire/src/Wire.cpp.o \
	libraries/advancedSerial/1.2.4/src/advancedSerial.cpp.o \
	libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp.o \

TARGETS = \
	vfr800.hex \
	vfr800.eep \

all: $(TARGETS)

vfr800.hex: vfr800.elf
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-objcopy" -O ihex -R .eeprom  "./vfr800.elf" "./vfr800.hex"

vfr800.eep: vfr800.elf
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "./vfr800.elf" "./vfr800.eep"

vfr800.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p  -o "./vfr800.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-size" -A "./vfr800.elf"

project/menu/menu.cpp.o: ../../menu/menu.cpp project/menu/menu.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"

project/menu/menu.cpp.d: ;

-include project/menu/menu.cpp.d 

project/menu/menuItem.cpp.o: ../../menu/menuItem.cpp project/menu/menuItem.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"

project/menu/menuItem.cpp.d: ;

-include project/menu/menuItem.cpp.d 

project/vfr800.cpp.o: ../../vfr800.cpp project/vfr800.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"

project/vfr800.cpp.d: ;

-include project/vfr800.cpp.d 


core/HardwareSerial1.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/Tone.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/IPAddress.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/hooks.c.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/wiring_digital.c.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/wiring_shift.c.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/WString.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d

core/HardwareSerial3.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/PluggableUSB.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/abi.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/WInterrupts.c.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/wiring.c.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/main.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/wiring_pulse.S.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/HardwareSerial0.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/HardwareSerial2.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/WMath.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/new.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/HardwareSerial.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/Stream.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/wiring_pulse.c.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/wiring_analog.c.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/USBCore.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/Print.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d



libraries/LiquidCrystal_I2C/1.1.2/LiquidCrystal_I2C.cpp.o: /home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2/LiquidCrystal_I2C.cpp libraries/LiquidCrystal_I2C/1.1.2/LiquidCrystal_I2C.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"

libraries/LiquidCrystal_I2C/1.1.2/LiquidCrystal_I2C.cpp.d: ;

-include libraries/LiquidCrystal_I2C/1.1.2/LiquidCrystal_I2C.cpp.d

libraries/Wire/src/utility/twi.c.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src/utility/twi.c libraries/Wire/src/utility/twi.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"

libraries/Wire/src/utility/twi.c.d: ;

-include libraries/Wire/src/utility/twi.c.d

libraries/Wire/src/Wire.cpp.o: /home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src/Wire.cpp libraries/Wire/src/Wire.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"

libraries/Wire/src/Wire.cpp.d: ;

-include libraries/Wire/src/Wire.cpp.d

libraries/advancedSerial/1.2.4/src/advancedSerial.cpp.o: /home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src/advancedSerial.cpp libraries/advancedSerial/1.2.4/src/advancedSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"

libraries/advancedSerial/1.2.4/src/advancedSerial.cpp.d: ;

-include libraries/advancedSerial/1.2.4/src/advancedSerial.cpp.d

libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp.o: /home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tomek/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal_I2C/1.1.2" -I"/home/tomek/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/tomek/.arduinocdt/libraries/advancedSerial/1.2.4/src" -I"/home/tomek/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" "$<" -o "$@"

libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp.d: ;

-include libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp.d

