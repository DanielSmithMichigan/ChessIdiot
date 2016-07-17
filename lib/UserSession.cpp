#ifndef UserSession_cpp
#define UserSession_cpp
	#include "UserSession.h"

	UserSession::UserSession(shared_ptr<Board> board) : board(move(board)) {
	}

	UserSession::~UserSession() {
	}

	void UserSession::waitForInput() {
		cin >> input;
    	useInput();
    	normalize();
	}

	void UserSession::useInput() {
		if (input == "W") {
			y--;
		} else if (input == "A") {
			x--;
		} else if (input == "S") {
			y++;
		} else if (input == "D") {
			x++;
		} else if (input == "E") {
			selectSquare();
		}
	}

	void UserSession::selectSquare() {
		int location = xyToInt(x, y);
		board->removeIndicatorColors();
		board->highlightMovesAt(x, y);
	}

	void UserSession::normalize() {
		x = max(x, 0);
		x = min(x, BOARD_WIDTH - 1);
		y = max(y, 0);
		y = min(y, BOARD_WIDTH - 1);
	}

	void UserSession::reset() {
		x = 0;
		y = 0;
	}
#endif