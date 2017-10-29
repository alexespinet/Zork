// Zork.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <conio.h>
#include "GameController.h"
#include <iostream>

void SplitString(const string &line, std::vector<std::string> &resultVector,const char spacer) {
	const char * str = line.c_str();
	do {
		const char *begin = str;
		while (*str !=spacer  && *str)
			str++;
		resultVector.push_back(string(begin, str));
	} while (0 != *str++);
}

int main()
{
	cout << "Wellcome to the best zork copy ever" << endl;
	char key;
	GameController game;
	std::vector<std::string> inputs;
	std::string input="";
	//Manage inputs and send them to gameController
	bool gameEnded = false;
	do {
		key = _getch();
		if (key == '\b') {
			if (input.length() > 0) {
				input.pop_back();
				cout << '\b';
				cout << " ";
				cout << '\b';
			}
		}
		else if (key != '\r') {
			input += key;
			cout << key;
		}
		else {
			SplitString(input, inputs, ' ');
			cout << endl;
			if (inputs.size() > 0)
				gameEnded = game.ManageInput(inputs);
			input = "";
			inputs.clear();
		}
		



	} while (!gameEnded);
	cout << "See you bro!!!!!!" << endl;
    return 0;
}

