#include "Color.h"

void Color::SetValue(int value) {
	int comparison = 255;
	//blue
	int bloo = value& comparison;
	bVal = bloo;
	//green
	value = value >> 8;
	int gren = value & comparison;
	gVal = gren;
	//red
	value = value >> 8;
	int rd = value & comparison;
	rVal = rd;

	// now for the hex

	string builder ="0x";

	string redP = "00";
	string greenP = "00";
	string blueP = "00";

	int temp = rd / 16;
	redP[0]=Convert(temp);
	temp = rd % 16;
	redP[1] = Convert(temp);

	temp = gren / 16;
	greenP[0] = Convert(temp);
	temp = gren % 16;
	greenP[1] = Convert(temp);

	temp = bloo / 16;
	blueP[0] = Convert(temp);
	temp = bloo % 16;
	blueP[1] = Convert(temp);

	builder += redP;
	builder += greenP;
	builder += blueP;

	hexVal = builder;
}

void Color:: SetName(string name) {
	this ->name = name;
}

unsigned char Color:: GetR() const {
	return rVal;
}
unsigned char Color:: GetG() const {
	return gVal;
}
unsigned char Color:: GetB() const{
	return bVal;
}

string Color:: GetHexValue() const {
	return hexVal;
}
string Color:: GetName() const{
	return name;
}

char Color::Convert(int toConvert) {
	switch (toConvert) {
	case 0:
		return '0';
		break;
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	case 10:
		return 'A';
		break;
	case 11:
		return 'B';
		break;
	case 12:
		return 'C';
		break;
	case 13:
		return 'D';
		break;
	case 14:
		return 'E';
		break;
	case 15:
		return 'F';
		break;
	default:
		return -1;
	}
}