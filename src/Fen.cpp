#ifndef Fen_cpp
#define Fen_cpp
	#include "Fen.h"

	Fen::Fen() {
	}

	Fen::~Fen() {
	}

	string Fen::readToken(string &str) {
		boost::trim_left(str);
		string token = str.substr(0, str.find(" "));
		str.erase(0, str.find(" "));
		return token;
	}

	void Fen::import(string fenString) {
		useBoardString(readToken(fenString));
		setPlayerTurn(readToken(fenString));
		setCastling(readToken(fenString));
		// setEnPassantTarget(readToken(fenString));
		// board->halfMoveClock = boost::lexical_cast<int>(readToken(fenString));
		// board->fullMoveClock = boost::lexical_cast<int>(readToken(fenString));
	}

	void Fen::setEnPassantTarget(string fenString) {
		// int location = fenString == "-" ?
		// 	SOMEWHERE_OFF_BOARD
		// 	: boardCoordToInt(fenString);
		// board->enPassantTarget = location;
		// board->initialEnPassantTarget = location;
	}

	int Fen::boardCoordToInt(string boardCoord) {
		int location = 0;
		for(char& c : boardCoord) {
			switch(c) {
				case 'a':
				case 'A':
				break;
				case 'b':
				case 'B':
					location += 1;
				break;
				case 'c':
				case 'C':
					location += 2;
				break;
				case 'd':
				case 'D':
					location += 3;
				break;
				case 'e':
				case 'E':
					location += 4;
				break;
				case 'f':
				case 'F':
					location += 5;
				break;
				case 'g':
				case 'G':
					location += 6;
				break;
				case 'h':
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
					int numericChar = '8' - c;
					location += ROWS(numericChar);
				break;
			}
		}
		return location;
	}

	void Fen::setPlayerTurn(string fenString) {
		for(char& c : fenString) {
			switch(c) {
				case 'w':
					Board::turn = WHITE;
				break;
				case 'b':
					Board::turn = BLACK;
				break;
			}
		}
	}

	void Fen::setCastling(string fenString) {
	}

	void Fen::useBoardString(string fenString) {
		// Board::reset();
		int x = 0, y = 0;
		for(char& c : fenString) {
			switch(c) {
				case 'R':
					Board::put(WHITE, ROOK, xyToInt(x, y));
					x++;
				break;
				case 'r':
					Board::put(BLACK, ROOK, xyToInt(x, y));
					x++;
				break;
				case 'N':
					Board::put(WHITE, KNIGHT, xyToInt(x, y));
					x++;
				break;
				case 'n':
					Board::put(BLACK, KNIGHT, xyToInt(x, y));
					x++;
				break;
				case 'B':
					Board::put(WHITE, BISHOP, xyToInt(x, y));
					x++;
				break;
				case 'b':
					Board::put(BLACK, BISHOP, xyToInt(x, y));
					x++;
				break;
				case 'Q':
					Board::put(WHITE, QUEEN, xyToInt(x, y));
					x++;
				break;
				case 'q':
					Board::put(BLACK, QUEEN, xyToInt(x, y));
					x++;
				break;
				case 'K':
					Board::put(WHITE, KING, xyToInt(x, y));
					x++;
				break;
				case 'k':
					Board::put(BLACK, KING, xyToInt(x, y));
					x++;
				break;
				case 'P':
					Board::put(WHITE, PAWN, xyToInt(x, y));
					x++;
				break;
				case 'p':
					Board::put(BLACK, PAWN, xyToInt(x, y));
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

	string Fen::getBoardSquares() {
		string allBoardSquares;
		for (int y = 0; y < ROW; y++) {
			if (y) {
				allBoardSquares += "/";
			}
			for (int x = 0; x < ROW; x++) {
				switch(Board::piecesIndex[ROWS(y) + x]) {
					case ROOK:
						allBoardSquares += Board::colorsIndex[ROWS(y) + x] == WHITE ? "R" : "r";
					break;
					case KNIGHT:
						allBoardSquares += Board::colorsIndex[ROWS(y) + x] == WHITE ? "N" : "n";
					break;
					case BISHOP:
						allBoardSquares += Board::colorsIndex[ROWS(y) + x] == WHITE ? "B" : "b";
					break;
					case KING:
						allBoardSquares += Board::colorsIndex[ROWS(y) + x] == WHITE ? "K" : "k";
					break;
					case QUEEN:
						allBoardSquares += Board::colorsIndex[ROWS(y) + x] == WHITE ? "Q" : "q";
					break;
					case PAWN:
						allBoardSquares += Board::colorsIndex[ROWS(y) + x] == WHITE ? "P" : "p";
					break;
					case EMPTY_SPACE:
					default:
						allBoardSquares += "E";
					break;
				}
			}
		}
		replaceSpacesWithNumbers(allBoardSquares);
		return allBoardSquares;
	}

	void Fen::replaceSpacesWithNumbers(string &boardString) {
		for (int i = 8; i >= 1; i--) {
			boardString = regex_replace(boardString, regex(string(i, 'E')), to_string(i));
		}
	}

	string Fen::getPlayerTurn() {
		switch(Board::turn) {
			case BLACK:
				return "b";
			default:
				return "w";
		}
	}

	string Fen::getCastling() {
		string output = "";
		return output;
	}

	string Fen::intToBoardCoord(int location) {
		int row = GET_ROW(location);
		string letters[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
		return "" + letters[location - ROWS(row)] + to_string((7 - row) + 1);
	}

	string Fen::getEnPassantTarget() {
		return "-";
	}

	string Fen::exportBoard() {
		return "" 
			+ getBoardSquares()
			+ " " + getPlayerTurn()
			+ " " + getCastling()
			+ " " + getEnPassantTarget();
			// + " " + to_string(board->halfMoveClock)
			// + " " + to_string(board->fullMoveClock);
	}

	string Fen::exportLegacyBoard() {
		return "" 
			+ getBoardSquares()
			+ " " + getPlayerTurn()
			+ " " + getCastling()
			+ " " + getEnPassantTarget();
	}
#endif