#include <iostream>
#include <fstream>
#include <array>

#define EEPROM "/sys/bus/i2c/devices/1-0054/eeprom"

using namespace std;

int main(void)
{
	array<char, 243> data;

	// Initialize the data
	data.fill(0);

	// Set the header
	data[0] = 0xAA; data[1] = 0x55; data[2] = 0x33; data[3] = 0xEE;

	// Set the EEPROM revision
	data[4] = 'A'; data[5] = '1';

	// Set the board name
	sprintf((data.data() + 6), "Beaglebone Sensor Cape");

	// Set the board version
	sprintf((data.data() + 38), "v0.9");

	// Set the manufacturer
	sprintf((data.data() + 42), "Michael Leonard");

	// Set the Part Number
	sprintf((data.data() + 58), "BB-SENSOR-CAPE");

	// Set the Number of pins
	data[75] = 0x16;

	// Set the serial number of the board
	sprintf((data.data() + 76), "011412340001");

	// Set the Pin 10 usage: Used, Input, 12-7 reserved, Fast Slew, Rx Enabled, Pullup, Pullup Disabled, Mode 7 => 0xA03F
	uint8_t offset = 174;
	data[offset] = 0xA; data[offset + 1] = 0x0; data[offset + 2] = 0x3; data[offset + 3] = 0xF;

	// Set the VDD_3V3B Current
	data[236] = 0x05; data[236 + 1] = 0xDC;

	// Set the VDD_5V Current
	data[238] = 0x5; data[238 + 1] = 0xDC;

	// Set the SYS_5V Current
	data[240] = 0x5; data[240 + 1] = 0xDC;

	// Now write the data to eeprom
	ofstream eeprom;
	eeprom.open(EEPROM, ofstream::out | ofstream::binary);
	if( !eeprom.is_open() )
	{
		cout << endl << "Failed to open i2c device for reading!" << endl;
		return -1;
	}
	cout << endl << "Write data to EEPROM...";
	eeprom.write(data.data(), data.size());
	cout << "Success!" << endl;

	eeprom.close();

	return 0;
}
