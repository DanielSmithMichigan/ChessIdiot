#ifndef TerminalDisplay_h
#define TerminalDisplay_h
	#include <stdint.h>
	#include <iostream>
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
			TerminalDisplay(Screen *screenInput, shared_ptr<Board> board);
			~TerminalDisplay();
	};
#endif