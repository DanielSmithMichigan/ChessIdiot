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
			string exportLegacyBoard();
	};
#endif