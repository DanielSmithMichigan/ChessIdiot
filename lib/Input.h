#ifndef Input_h
#define Input_h
	#include <iostream>
	#include <termios.h>
	#include <stdio.h>
	using namespace std;

	class Input {
		private:
			struct termios t;
			void disableBuffer();
			void enableBuffer();
		public:
			char getCharacter();
			Input();
			~Input();

	};
#endif