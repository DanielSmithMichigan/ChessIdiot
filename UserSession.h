#ifndef UserSession_h
#define UserSession_h
	#include <stdint.h>
	#include <iostream>
	#include <string>
	#include "utilities.h"
	#include <termios.h>
	#include "Input.h"
	#include <memory>
	#include "globals.h"
	#include "Board.h"

	using namespace std;

	class UserSession {
		private:
			unique_ptr<Input> userInput;
			shared_ptr<Board> board;
			string input;
			bool active;
			int x;
			int y;
		public:
			void waitForInput();
			void useInput();
			void reset();
			void normalize();
			void selectSquare();
			UserSession(shared_ptr<Board> board);
			~UserSession();
	};
#endif