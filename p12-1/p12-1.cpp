#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void pressEnterToContinue();
bool readFromFile(string filename);
int countWords(string thisLine);
int countChars(string thisLine);


int main() {
	string datafile;
	cout << "input file: ";
	getline(cin, datafile);

	bool status = readFromFile(datafile);

	pressEnterToContinue();
}

void pressEnterToContinue() {
	cout << "\nPress enter to continue... \n";
	cin.clear();
	while (cin.get() != '\n') continue;
}

bool readFromFile(string filename) {
	ifstream inFile;
	string thisLine;
	int wordCount = 0;
	int charCount = 0;
	inFile.open(filename);

	if (inFile.fail()) {
		cout << "read error - sorry\n";
		return false;
	}

	while (true) {
		if (inFile.fail()) break;
		thisLine.clear();
		getline(inFile, thisLine);

		wordCount += countWords(thisLine);
		charCount += countChars(thisLine);
	}

	cout << "    Words: " << wordCount << "\n";
	cout << "Characters:" << charCount << "\n";

	inFile.close();
	return true;
}

int countWords(string thisLine) {
	int count = 0;
	int length = thisLine.length();

	for (int i = 0; i < length - 1; i++) {
		if ((thisLine[i] == ' ' && !isspace(thisLine[i + 1])) || i == 0) {
			count++;
		}
	}
	return count;
}

int countChars(string thisLine) {
	int count = 0;

	for (int i = 0; i < thisLine.length(); i++) {
		if (thisLine[i] != ' ') {
			count++;
		}
	}
	return count;
}