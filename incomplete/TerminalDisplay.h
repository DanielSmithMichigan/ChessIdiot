#ifndef TerminalDisplay_h
#define TerminalDisplay_h
	#include <stdint.h>
	#include <iostream>
	#include <string>
	#include "Board.h"
	#include "Square.h"
	#include <ncurses.h>

	using namespace std;

	class TerminalDisplay {
		private:
			shared_ptr<Board> board;
			int colors[8][8];
		public:
			void draw();
			void drawSquare(int x, int y);
			int getSquareXOffset(int x, int y);
			int getSquareYOffset(int x, int y);
			char getCharacterForLocation(int column, int row, int x, int y);
			int getForegroundColorForLocation(int x, int y);
			int getBackgroundColorForLocation(int x, int y);
			void drawMargin();
			void write(char character, int background, int foreground);
			TerminalDisplay(shared_ptr<Board> board);
			~TerminalDisplay();
	};
#endif