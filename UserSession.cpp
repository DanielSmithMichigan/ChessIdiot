#ifndef UserSession_cpp
#define UserSession_cpp
	#include "UserSession.h"

	UserSession::UserSession() {
	}

	UserSession::~UserSession() {
	}

	void UserSession::waitForInput() {
    	getch();
    	// useInput();
	}

	void UserSession::useInput() {
		if (input == "W") {
			y++;
		} else if (input == "A") {
			x--;
		} else if (input == "S") {
			y--;
		} else if (input == "D") {
			x++;
		}
		waitForInput();
	}

	void UserSession::reset() {
		x = 0;
		y = 0;
	}

	bool UserSession::isSelected(int location) {
		return xyToInt(x, y) == location;
	}
#endif