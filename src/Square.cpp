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
		number = xyToInt(x, y);
	}

	void Square::setPiece(uint64_t _piece, uint64_t _color) {
		piece = _piece;
		color = _color;
	}

	void Square::resetFeatures() {
		foregroundColor = defaultForegroundColor;
		backgroundColor = defaultBackgroundColor;
		selected = false;
		highlighted = false;
	}

	void Square::select() {
		if (piece == EMPTY_SPACE) {
			return;
		}
		selected = true;
	}

	void Square::highlight() {
		highlighted = true;
	}

	bool Square::hasPiece() {
		return piece != EMPTY_SPACE;
	}

	bool Square::matches(uint64_t bitboard) {
		return (identityBoard & bitboard) > 0;
	}

	void Square::doIfMatches(uint64_t bitboard, int action) {
		if (matches(bitboard)) {
			switch(action) {
				case HIGHLIGHT:
					highlight();
				break;
				case SELECT:
					select();
				break;
			}
		}
	}
#endif