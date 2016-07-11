#ifndef UserSession_h
#define UserSession_h
	#include <stdint.h>
	#include <iostream>
	#include <string>
	#include "utilities.h"
	#include <ncurses.h>

	using namespace std;

	class UserSession {
		private:
			int x;
			int y;
			string input;
		public:
			bool isSelected(int location);
			void waitForInput();
			void useInput();
			void reset();
			UserSession();
			~UserSession();
	};
#endif