#ifndef TerminalDisplay_h
#define TerminalDisplay_h
	#include <stdint.h>
	#include <iostream>
	#include <string>
	#include "Board.h"
	#include "Screen.h"
	#include "Square.h"
	#include "UserSession.h"

	using namespace std;

	class TerminalDisplay {
		private:
			unique_ptr<Screen> screen;
			shared_ptr<Board> board;
			shared_ptr<UserSession> userSession;
		public:
			void draw();
			void drawSquare(int squareNum);
			int getSquareXOffset(int squareNum, int column);
			int getSquareYOffset(int squareNum, int row);
			string getCharacterForLocation(int x, int y, int squareNum);
			string getForegroundColorForLocation(int x, int y, int squareNum);
			string getBackgroundColorForLocation(int x, int y, int squareNum);
			void drawMargin();
			TerminalDisplay(Screen *screenInput, shared_ptr<Board> board, shared_ptr<UserSession> userSession);
			~TerminalDisplay();
	};
#endif