#ifndef BGame_h
#define BGame_h
	#include "Square.h"
	#include "globals.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <vector>
	#include "Board.h"
	#include "SelectedSquare.h"
	#include "TerminalDisplay.h"

	using namespace std;

	class Game {
		private:
			shared_ptr<Board> board;
			shared_ptr<SelectedSquare> selectedSquare;
			shared_ptr<TerminalDisplay> terminalDisplay;
		public:
			Game(shared_ptr<Board> board, shared_ptr<SelectedSquare> selectedSquare, shared_ptr<TerminalDisplay> terminalDisplay);
			~Game();
			void begin();
	};
#endif