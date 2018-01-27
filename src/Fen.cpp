#ifndef Fen_cpp
#define Fen_cpp
	#include "Fen.h"

	Fen::Fen() {
	}

	Fen::~Fen() {
	}

	void Fen::import(string fenString) {
		Board::reset();
		useBoardString(readToken(fenString));
		setPlayerTurn(readToken(fenString));
		setCastling(readToken(fenString));
		setEnPassantTarget(readToken(fenString));
		readHalfMoveClock(readToken(fenString));
		// board->fullMoveClock = boost::lexical_cast<int>(readToken(fenString));
	}

	void Fen::readHalfMoveClock(string fenString) {
		if (fenString == "") {
			return;
		}
		Board::currentState->halfMoveCount = boost::lexical_cast<int>(fenString);
	}

	void Fen::setEnPassantTarget(string fenString) {
		if (fenString == "-") {
			return;
		}
		Board::currentState->enPassantTarget = boardCoordToInt(fenString);
		Board::currentState->zobrist ^= Zobrist::EnPassant[Board::currentState->enPassantTarget];
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
		
		if (Board::turn == BLACK) {
			Board::currentState->zobrist ^= Zobrist::BlackToMove;
		}
	}

	void Fen::setCastling(string fenString) {
		int x = 0, y = 0;
		for(char& c : fenString) {
			switch(c) {
				case 'K':
					Board::currentState->castlingRights |= WHITE_CAN_CASTLE_RIGHT;
				break;
				case 'Q':
					Board::currentState->castlingRights |= WHITE_CAN_CASTLE_LEFT;
				break;
				case 'k':
					Board::currentState->castlingRights |= BLACK_CAN_CASTLE_RIGHT;
				break;
				case 'q':
					Board::currentState->castlingRights |= BLACK_CAN_CASTLE_LEFT;
				break;
			}
		}
		
		Board::currentState->zobrist ^= Zobrist::CastlingRights[Board::currentState->castlingRights];
	}

	void Fen::useBoardString(string fenString) {
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
		if (Board::currentState->castlingRights & WHITE_CAN_CASTLE_RIGHT) {
			output += "K";
		}
		if (Board::currentState->castlingRights & WHITE_CAN_CASTLE_LEFT) {
			output += "Q";
		}
		if (Board::currentState->castlingRights & BLACK_CAN_CASTLE_RIGHT) {
			output += "k";
		}
		if (Board::currentState->castlingRights & BLACK_CAN_CASTLE_LEFT) {
			output += "q";
		}
		if (output == "") {
			return "-";
		}
		return output;
	}

	string Fen::getEnPassantTarget() {
		if (Board::currentState->enPassantTarget == NO_EN_PASSANT) {
			return "-";
		}
		return intToBoardCoord(Board::currentState->enPassantTarget);
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

	string Fen::exportZobristInfo() {
		return "" 
			+ getBoardSquares()
			+ " " + getPlayerTurn()
			+ " " + getCastling()
			+ " " + getEnPassantTarget();
	}
#endif