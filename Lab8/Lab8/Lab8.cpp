#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <sstream>

#include "Color.h"
using namespace std;

void ReadFile(const char* filename, map<string, Color>& colors);
void PrintColors(const map<string, Color>& colors);
void PrintColor(const Color& color);
void SearchForColor(map<string, Color>& colors);

// "load a file, converts the values to hex/rgb values, and stores the list of colors in a std:: map object"

int main()
{
	cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
	cout << "7. Load all 6 files" << endl;
	int choice;
	cin >> choice;

	map<string, Color> colors;
	if (choice >= 1 && choice <= 6)
	{
		string file = "colors" + to_string(choice) + ".txt";
		ReadFile(file.c_str(), colors);
	}
	else if (choice == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}
	}

	// Secondary menu
	cout << "1. Show all colors" << endl;
	cout << "2. Search for a color" << endl;
	cin >> choice;

	if (choice == 1)
		PrintColors(colors);
	else if (choice == 2)
		SearchForColor(colors);
	return 0;
}

void ReadFile(const char* filename, map<string, Color>& colors)
{
	// TODO: Read the file, create and store some Color objects
	ifstream reading(filename, ios_base::binary);
	string currentColor;
	while (getline(reading, currentColor)) {
		Color newColor;

		istringstream reading(currentColor);

		string name;
		getline(reading, name, ' ');

		string number;
		getline(reading, number );
		int value = stoi(number);

		newColor.SetName(name);
		newColor.SetValue(value);

		colors.emplace(newColor.GetName(), newColor);
	}
}
void PrintColors(const map<string, Color>& colors)
{
	// TODO: iterate through all entries in the map and print each color, one at a time
	// Print out the color count afterward

	auto iter = colors.begin();
	int count = 0;
	for (iter = colors.begin(); iter != colors.end(); iter++) {
		PrintColor(iter->second);
		count += 1;
	}
	cout << "Number of colors: " << count << endl;

}
void PrintColor(const Color& color)
{
	cout << left << setw(20) << color.GetName();
	cout << right << setw(10) << color.GetHexValue();
	cout << "\t\t" << (int)color.GetR() << "," << (int)color.GetG() << "," << (int)color.GetB() << endl;
}
void SearchForColor(map<string, Color>& colors)
{
	// TODO: Get some input, check if that key exists, then print out the color (or an error message)
	string toFind;
	cin >> toFind;
	auto iter = colors.find(toFind);
	if (iter != colors.end()) {
		PrintColor(iter->second);
	}
	else {
		cout << toFind << "not found!" << endl;
	}
}