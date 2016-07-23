#ifndef BGame_h
#define BGame_h
	#include "Square.h"
	#include "globals.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <vector>
	#include "Board.h"

	using namespace std;

	class Game {
		private:
			shared_ptr<Board> board;
		public:
			Game(shared_ptr<Board> board);
			~Game();
	};
#endif