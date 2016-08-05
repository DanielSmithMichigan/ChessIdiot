#ifndef UserCommand_h
#define UserCommand_h
	#include <iostream>
	#include <string>
	#include "utilities.h"
	#include "globals.h"
	#include <ncurses.h>

	using namespace std;

	class UserCommand {
		private:
			char input;
			bool active;
			int x;
			int y;
		public:
			void get();
			void useInput();
			void reset();
			void normalize();
			UserCommand();
			~UserCommand();
	};
#endif