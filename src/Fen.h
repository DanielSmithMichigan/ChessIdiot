#ifndef Fen_h
#define Fen_h
	#include <string>
	#include <regex>
	#include <memory>
	#include <iostream>
	#include "Board.h"
	#include "Globals.h"
	#include "Utility.h"
	using namespace std;

	class Fen {
		private:
		public:
			Fen();
			~Fen();
			static void import(string fenString);
			static string exportBoard();
			static void useBoardString(string boardString);
			static void setPlayerTurn(string playerTurn);
			static void setCastling(string castling);
			static void setEnPassantTarget(string enPassantTarget);
			static void readHalfMoveClock(string fenString);
			static string getBoardSquares();
			static void replaceSpacesWithNumbers(string &boardString);
			static string getPlayerTurn();
			static string getCastling();
			static string getEnPassantTarget();
			static string exportLegacyBoard();
			static string exportZobristInfo();
	};
#endif