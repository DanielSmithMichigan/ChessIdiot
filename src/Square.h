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
			void doIfMatches(uint64_t bitboard, int action);
			void highlight();
			bool hasPiece();
			bool selected = false;
			bool highlighted = false;
			Square(int x, int y);
			~Square();
	};
#endif