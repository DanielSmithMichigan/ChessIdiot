#ifndef UserCommand_h
#define UserCommand_h
	#include <stdint.h>
	#include <iostream>
	#include <string>
	#include "utilities.h"
	#include <termios.h>
	#include <memory>
	#include "globals.h"

	using namespace std;

	class UserCommand {
		private:
			string input;
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