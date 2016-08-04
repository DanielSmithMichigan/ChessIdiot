#ifndef BGame_h
#define BGame_h
	#include "Square.h"
	#include "globals.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <vector>
	#include "Board.h"
	#include "UserCommand.h"

	using namespace std;

	class Game {
		private:
			shared_ptr<Board> board;
			unique_ptr<UserCommand> userCommand;
		public:
			Game(shared_ptr<Board> board, UserCommand *userCommandInput);
			~Game();
	};
#endif