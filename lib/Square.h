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
			void setNumber();
			void setIdentityBoard();
			bool matches(uint8_t bitboard);
			uint8_t identityBoard;
			bool active = false;
			int number;
		public:
			int x;
			int y;
			uint64_t piece = EMPTY_SPACE;
			uint64_t color;
			string foregroundColor;
			string defaultForegroundColor;
			string backgroundColor;
			string defaultBackgroundColor;
			void setPiece(uint64_t piece, uint64_t color);
			void resetFeatures();
			void select();
			void highlightIfMatches(uint8_t bitboard);
			void highlight();
			bool hasPiece();
			Square(int x, int y);
			~Square();
	};
#endif