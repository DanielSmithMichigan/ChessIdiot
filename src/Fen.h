#ifndef Fen_h
#define Fen_h
	#include <string>
	#include <memory>
	#include "Board.h"
	#include "utilities.h"
	#define BLACK_ROOK_LEFT 0
	#define BLACK_ROOK_RIGHT 7
	#define WHITE_ROOK_LEFT ROWS(7)
	#define WHITE_ROOK_RIGHT ROWS(7) + 7

	using namespace std;

	class Fen {
		private:
			shared_ptr<Board> board;
		public:
			Fen(shared_ptr<Board> board);
			~Fen();
			string readToken(string &str);
			void import(string fenString);
			void useBoardString(string boardString);
			void setPlayerTurn(string playerTurn);
			void setCastling(string castling);
			void setEnPassantTarget(string enPassantTarget);
			int boardCoordToInt(string boardCoord);
	};
#endif