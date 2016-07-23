#ifndef TerminalDisplay_h
#define TerminalDisplay_h
	#include <stdint.h>
	#include <iostream>
	#include <string>
	#include "Board.h"
	#include "Screen.h"
	#include "Square.h"

	using namespace std;

	class TerminalDisplay {
		private:
			unique_ptr<Screen> screen;
			shared_ptr<Board> board;
		public:
			void draw();
			void drawSquare(int x, int y);
			int getSquareXOffset(int x, int y);
			int getSquareYOffset(int x, int y);
			string getCharacterForLocation(int column, int row, int x, int y);
			string getForegroundColorForLocation(int x, int y);
			string getBackgroundColorForLocation(int x, int y);
			void drawMargin();
			TerminalDisplay(Screen *screenInput, shared_ptr<Board> board);
			~TerminalDisplay();
	};
#endif