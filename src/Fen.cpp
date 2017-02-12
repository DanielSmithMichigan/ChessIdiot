#ifndef Fen_cpp
#define Fen_cpp
	#include "Fen.h"

	Fen::Fen(shared_ptr<Board> board) : board(board) {
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
		setEnPassantTarget(readToken(fenString));
		board->halfMoveClock = boost::lexical_cast<int>(readToken(fenString));
		board->fullMoveClock = boost::lexical_cast<int>(readToken(fenString));
	}

	void Fen::setEnPassantTarget(string fenString) {
		int location = fenString == "-" ?
			SOMEWHERE_OFF_BOARD
			: boardCoordToInt(fenString);
		board->enPassantTarget = location;
		board->initialEnPassantTarget = location;
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
		board->firstMove[WHITE_KING_POS] = false;
		board->firstMove[BLACK_ROOK_LEFT] = false;
		board->firstMove[BLACK_ROOK_RIGHT] = false;
		board->firstMove[BLACK_KING_POS] = false;
		for(char& c: fenString) {
			switch(c) {
				case 'K':
					board->firstMove[WHITE_ROOK_RIGHT] = true;
					board->firstMove[WHITE_KING_POS] = true;
				break;
				case 'Q':
					board->firstMove[WHITE_ROOK_LEFT] = true;
					board->firstMove[WHITE_KING_POS] = true;
				break;
				case 'k':
					board->firstMove[BLACK_ROOK_RIGHT] = true;
					board->firstMove[BLACK_KING_POS] = true;
				break;
				case 'q':
					board->firstMove[BLACK_ROOK_LEFT] = true;
					board->firstMove[BLACK_KING_POS] = true;
				break;
			}
		}
	}

	void Fen::useBoardString(string fenString) {
		board->empty();
		int x = 0, y = 0;
		for(char& c : fenString) {
			switch(c) {
				case 'R':
					board->place(WHITE_ROOK, xyToInt(x, y));
					x++;
				break;
				case 'r':
					board->place(BLACK_ROOK, xyToInt(x, y));
					x++;
				break;
				case 'N':
					board->place(WHITE_KNIGHT, xyToInt(x, y));
					x++;
				break;
				case 'n':
					board->place(BLACK_KNIGHT, xyToInt(x, y));
					x++;
				break;
				case 'B':
					board->place(WHITE_BISHOP, xyToInt(x, y));
					x++;
				break;
				case 'b':
					board->place(BLACK_BISHOP, xyToInt(x, y));
					x++;
				break;
				case 'Q':
					board->place(WHITE_QUEEN, xyToInt(x, y));
					x++;
				break;
				case 'q':
					board->place(BLACK_QUEEN, xyToInt(x, y));
					x++;
				break;
				case 'K':
					board->place(WHITE_KING, xyToInt(x, y));
					x++;
				break;
				case 'k':
					board->place(BLACK_KING, xyToInt(x, y));
					x++;
				break;
				case 'P':
					board->place(WHITE_PAWN, xyToInt(x, y));
					x++;
				break;
				case 'p':
					board->place(BLACK_PAWN, xyToInt(x, y));
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
		for (int y = 0; y < BOARD_WIDTH; y++) {
			if (y) {
				allBoardSquares += "/";
			}
			for (int x = 0; x < BOARD_WIDTH; x++) {
				switch(board->squares[ROWS(y) + x]) {
					case BLACK_ROOK:
						allBoardSquares += "r";
					break;
					case WHITE_ROOK:
						allBoardSquares += "R";
					break;
					case BLACK_KNIGHT:
						allBoardSquares += "n";
					break;
					case WHITE_KNIGHT:
						allBoardSquares += "N";
					break;
					case BLACK_BISHOP:
						allBoardSquares += "b";
					break;
					case WHITE_BISHOP:
						allBoardSquares += "B";
					break;
					case BLACK_KING:
						allBoardSquares += "k";
					break;
					case WHITE_KING:
						allBoardSquares += "K";
					break;
					case BLACK_QUEEN:
						allBoardSquares += "q";
					break;
					case WHITE_QUEEN:
						allBoardSquares += "Q";
					break;
					case BLACK_PAWN:
						allBoardSquares += "p";
					break;
					case WHITE_PAWN:
						allBoardSquares += "P";
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
		switch(board->turn) {
			case BLACK:
				return "b";
			default:
				return "w";
		}
	}

	string Fen::getCastling() {
		string output = "";
		if (board->firstMove[WHITE_KING_POS]
			&& board->firstMove[WHITE_ROOK_RIGHT]) {
			output += "K";
		}
		if (board->firstMove[WHITE_KING_POS]
			&& board->firstMove[WHITE_ROOK_LEFT]) {
			output += "Q";
		}
		if (board->firstMove[BLACK_KING_POS]
			&& board->firstMove[BLACK_ROOK_RIGHT]) {
			output += "k";
		}
		if (board->firstMove[BLACK_KING_POS]
			&& board->firstMove[BLACK_ROOK_LEFT]) {
			output += "q";
		}
		if (output == "") {
			return "-";
		}
		return output;
	}

	string Fen::intToBoardCoord(int location) {
		int row = GET_ROW(location);
		string letters[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
		return "" + letters[location - ROWS(row)] + to_string((7 - row) + 1);
	}

	string Fen::getEnPassantTarget() {
		if (board->enPassantTarget == SOMEWHERE_OFF_BOARD) {
			return "-";
		}
		return intToBoardCoord(board->enPassantTarget);
	}

	string Fen::exportBoard() {
		return "" 
			+ getBoardSquares()
			+ " " + getPlayerTurn()
			+ " " + getCastling()
			+ " " + getEnPassantTarget()
			+ " " + to_string(board->halfMoveClock)
			+ " " + to_string(board->fullMoveClock);
	}

	string Fen::exportLegacyBoard() {
		return "" 
			+ getBoardSquares()
			+ " " + getPlayerTurn()
			+ " " + getCastling()
			+ " " + getEnPassantTarget();
	}
#endif