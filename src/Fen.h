#ifndef Fen_h
#define Fen_h
	#include <string>
	#include <regex>
	#include <memory>
	#include "Board.h"
	#include "Globals.h"
	#include "Utility.h"
	#include <boost/algorithm/string/trim.hpp>
	#include <boost/format.hpp>
	#include <boost/lexical_cast.hpp>
	#include <iostream>
	using namespace std;

	class Fen {
		private:
		public:
			Fen();
			~Fen();
			static string readToken(string &str);
			static void import(string fenString);
			static string exportBoard();
			static void useBoardString(string boardString);
			static void setPlayerTurn(string playerTurn);
			static void setCastling(string castling);
			static void setEnPassantTarget(string enPassantTarget);
			static int boardCoordToInt(string boardCoord);
			static string getBoardSquares();
			static void replaceSpacesWithNumbers(string &boardString);
			static string getPlayerTurn();
			static string getCastling();
			static string intToBoardCoord(int location);
			static string getEnPassantTarget();
			static string exportLegacyBoard();
			static string exportZobristInfo();
	};
#endif