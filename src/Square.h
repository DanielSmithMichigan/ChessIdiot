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
			bool matches(uint64_t bitboard);
			uint64_t identityBoard;
			bool active = false;
		public:
			int number;
			int x;
			int y;
			uint64_t piece = EMPTY_SPACE;
			uint64_t color = EMPTY_SPACE;
			string foregroundColor;
			string defaultForegroundColor;
			string backgroundColor;
			string defaultBackgroundColor;
			void setPiece(uint64_t piece, uint64_t color);
			void resetFeatures();
			void select();
			void highlightIfMatches(uint64_t bitboard);
			void highlight();
			bool hasPiece();
			Square(int x, int y);
			~Square();
	};
#endif