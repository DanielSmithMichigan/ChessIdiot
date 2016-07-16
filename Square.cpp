#ifndef Square_cpp
#define Square_cpp
	#include "Square.h"

	Square::Square(int x, int y) : x(x), y(y) {
		setNumber();
		setIdentityBoard();
		setColor();
		resetFeatures();
	}

	Square::~Square() {
	}

	void Square::setIdentityBoard() {
		identityBoard = (uint64_t)1 << number;
	}

	void Square::setColor() {
		defaultForegroundColor = even(x) ?
			even(y) ? "BLACK" : "WHITE"
			: even(y) ? "WHITE" : "BLACK";
		defaultBackgroundColor = defaultForegroundColor == "WHITE" ? "BLACK" : "WHITE";
	}

	void Square::setNumber() {
		number = x * 8 + y;
	}

	void Square::setPiece(uint64_t _piece, uint64_t _color) {
		piece = _piece;
		color = _color;
	}

	void Square::resetFeatures() {
		foregroundColor = defaultForegroundColor;
		backgroundColor = defaultBackgroundColor;
		active = false;
	}

	void Square::select() {
		if (piece == EMPTY_SPACE) {
			return;
		}
		backgroundColor = "GREEN";
		active = true;
	}

	void Square::highlight() {
		backgroundColor = "PURPLE";
	}

	bool Square::hasPiece() {
		return piece != EMPTY_SPACE;
	}

	bool Square::matches(uint8_t bitboard) {
		return (identityBoard & bitboard) > 0;
	}

	void Square::highlightIfMatches(uint8_t bitboard) {
		if (matches(bitboard)) {
			select();
		}
	}
#endif