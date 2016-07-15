#ifndef Square_h
#define Square_h
	#include <stdint.h>
	#include <string>
	#include "utilities.h"
	#include "globals.h"

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
			uint64_t piece = EMPTY_SPACE;
			uint64_t color;
			string foregroundColor;
			string defaultForegroundColor;
			string backgroundColor;
			string defaultBackgroundColor;
			void setPiece(uint64_t piece, uint64_t color);
			void resetColors();
			void select();
			Square(int number);
			~Square();
	};
#endif