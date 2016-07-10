#ifndef Square_h
#define Square_h
	#include <stdint.h>
	#include <string>
	#include "utilities.h"

	using namespace std;

	class Square {
		private:
			void setColor();
			void setColumn();
			void setRow();
		public:
			int number;
			int column;
			int row;
			string foregroundColor;
			string backgroundColor;
			Square(int number);
			~Square();
	};
#endif