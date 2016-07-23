#ifndef UserCommand_cpp
#define UserCommand_cpp
	#include "UserCommand.h"

	UserCommand::UserCommand() {
	}

	UserCommand::~UserCommand() {
	}

	void UserCommand::get() {
		cin >> input;
    	useInput();
    	normalize();
	}

	void UserCommand::useInput() {
		if (input == "W") {
			y--;
		} else if (input == "A") {
			x--;
		} else if (input == "S") {
			y++;
		} else if (input == "D") {
			x++;
		} else if (input == "E") {
			// selectSquare();
			// Return selectedSquare
		}
	}

	void UserCommand::normalize() {
		x = max(x, 0);
		x = min(x, BOARD_WIDTH - 1);
		y = max(y, 0);
		y = min(y, BOARD_WIDTH - 1);
	}

	void UserCommand::reset() {
		x = 0;
		y = 0;
	}
#endif