#pragma once
#include <string>
#include <iostream>

using namespace std;

class Color
{

	string name;
	string hexVal;
	unsigned char rVal;
	unsigned char gVal;
	unsigned char bVal;

public:
	void SetValue(int value);
	void SetName(string name);

	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;
	string GetHexValue() const;
	string GetName() const;
	char Convert(int toConvert);

};

