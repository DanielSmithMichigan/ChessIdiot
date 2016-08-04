#ifndef Screen_h
#define Screen_h
	#include <stdint.h>
	#include <iostream>
	#include "globals.h"

	using namespace std;

	class Screen {
		private:
		public:
			virtual void clear() = 0;
			virtual void gotoxy(int x, int y) = 0;
			virtual void write(string value, string foregroundColor = "WHITE", string backgroundColor = "BLACK") = 0;
			Screen();
			~Screen();
	};
#endif