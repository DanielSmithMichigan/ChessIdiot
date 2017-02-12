#ifndef Fen_h
#define Fen_h
	#include <string>
	#include <regex>
	#include <memory>
	#include "Board.h"
	#include "utilities.h"
	#include <boost/algorithm/string/trim.hpp>
	#include <boost/format.hpp>
	#include <boost/lexical_cast.hpp>
	#define BLACK_ROOK_LEFT 0
	#define BLACK_ROOK_RIGHT 7
	#define BLACK_KING_POS 4
	#define WHITE_ROOK_LEFT ROWS(7)
	#define WHITE_ROOK_RIGHT ROWS(7) + 7
	#define WHITE_KING_POS 116

	using namespace std;

	class Fen {
		private:
			shared_ptr<Board> board;
		public:
			Fen(shared_ptr<Board> board);
			~Fen();
			string readToken(string &str);
			void import(string fenString);
			string exportBoard();
			void useBoardString(string boardString);
			void setPlayerTurn(string playerTurn);
			void setCastling(string castling);
			void setEnPassantTarget(string enPassantTarget);
			int boardCoordToInt(string boardCoord);
			string getBoardSquares();
			void replaceSpacesWithNumbers(string &boardString);
			string getPlayerTurn();
			string getCastling();
			string intToBoardCoord(int location);
			string getEnPassantTarget();
	};
#endif