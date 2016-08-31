#ifndef SelectedSquare_h
#define SelectedSquare_h
	#include <iostream>
	#include <string>
	#include "utilities.h"
	#include "globals.h"
	#include <memory>
	#include "Board.h"
	#include "TerminalDisplay.h"
	#include <ncurses.h>

	using namespace std;

	class SelectedSquare {
		private:
			shared_ptr<Board> board;
			shared_ptr<TerminalDisplay> terminalDisplay;
			int input;
			bool active;
			bool selected;
			int x;
			int y;
		public:
			void get();
			void getInput();
			void useInput();
			void reset();
			void normalize();
			void display();
			void resetBoard();
			SelectedSquare(shared_ptr<Board> board, shared_ptr<TerminalDisplay> terminalDisplay);
			~SelectedSquare();
	};
#endif