#ifndef UbuntuScreen_h
#define UbuntuScreen_h
	#include "Screen.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <map>
	#include <string>

	using namespace std;

	class UbuntuScreen : public Screen {
		private:
			map<string, string> color;
		public:
			void clear();
			void gotoxy(int x, int y);
			void write(string value, string foregroundColor, string backgroundColor);
			UbuntuScreen();
			~UbuntuScreen();
	};
#endif