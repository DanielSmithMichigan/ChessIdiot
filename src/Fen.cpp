#ifndef Fen_cpp
#define Fen_cpp
	#include "Fen.h"

	Fen::Fen(shared_ptr<Board> board) : board(board) {
	}

	Fen::~Fen() {
	}

	string Fen::readToken(string &str) {
		string token = str.substr(0, str.find(" "));
		str.erase(0, str.find(" "));
		return token;
	}

	void Fen::tokenizeFen(string fenString) {
		useBoardString(readToken(fenString));
		setPlayerTurn(readToken(fenString));
		setCastling(readToken(fenString));
		setEnPassantTarget(readToken(fenString));
		string halfMoveClock = readToken(fenString);
		string fullMoveNumber = readToken(fenString);
	}

	void Fen::setEnPassantTarget(string fenString) {
		board->enPassantTarget = boardCoordToInt(fenString);
	}

	int Fen::boardCoordToInt(string boardCoord) {
		int location = 0;
		for(char& c : boardCoord) {
			switch(c) {
				case 'A':
				break;
				case 'B':
					location += 1;
				break;
				case 'C':
					location += 2;
				break;
				case 'D':
					location += 3;
				break;
				case 'E':
					location += 4;
				break;
				case 'F':
					location += 5;
				break;
				case 'G':
					location += 6;
				break;
				case 'H':
					location += 7;
				break;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
					location += ROWS(c - '1');
				break;
			}
		}
		return location;
	}

	void Fen::setPlayerTurn(string fenString) {
		for(char& c : fenString) {
			switch(c) {
				case 'w':
					board->turn = WHITE;
				break;
				case 'b':
					board->turn = BLACK;
				break;
			}
		}
	}

	void Fen::setCastling(string fenString) {
		board->firstMove[WHITE_ROOK_LEFT] = false;
		board->firstMove[WHITE_ROOK_RIGHT] = false;
		board->firstMove[BLACK_ROOK_LEFT] = false;
		board->firstMove[BLACK_ROOK_RIGHT] = false;
		for(char& c: fenString) {
			switch(c) {
				case 'K':
					board->firstMove[WHITE_ROOK_RIGHT] = true;
				break;
				case 'Q':
					board->firstMove[WHITE_ROOK_LEFT] = true;
				break;
				case 'k':
					board->firstMove[BLACK_ROOK_RIGHT] = true;
				break;
				case 'q':
					board->firstMove[BLACK_ROOK_LEFT] = true;
				break;
			}
		}
	}

	void Fen::useBoardString(string fenString) {
		board->initializeEmptyBoard();
		board->initializeFirstMove();
		int x = 0, y = 0;
		for(char& c : fenString) {
			switch(c) {
				case 'R':
					board->squares[xyToInt(x, y)] = WHITE_ROOK;
					x++;
				break;
				case 'r':
					board->squares[xyToInt(x, y)] = BLACK_ROOK;
					x++;
				break;
				case 'N':
					board->squares[xyToInt(x, y)] = WHITE_KNIGHT;
					x++;
				break;
				case 'n':
					board->squares[xyToInt(x, y)] = BLACK_KNIGHT;
					x++;
				break;
				case 'B':
					board->squares[xyToInt(x, y)] = WHITE_BISHOP;
					x++;
				break;
				case 'b':
					board->squares[xyToInt(x, y)] = BLACK_BISHOP;
					x++;
				break;
				case 'Q':
					board->squares[xyToInt(x, y)] = WHITE_QUEEN;
					x++;
				break;
				case 'q':
					board->squares[xyToInt(x, y)] = BLACK_QUEEN;
					x++;
				break;
				case 'K':
					board->squares[xyToInt(x, y)] = WHITE_KING;
					x++;
				break;
				case 'k':
					board->squares[xyToInt(x, y)] = BLACK_KING;
					x++;
				break;
				case '/':
					y++;
					x = 0;
				break;
				case '8':
				case '7':
				case '6':
				case '5':
				case '4':
				case '3':
				case '2':
				case '1':
					x += (c - '0');
				break;
			}
		}
	}
#endif