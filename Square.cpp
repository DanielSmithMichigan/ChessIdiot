#ifndef Square_cpp
#define Square_cpp
	#include "Square.h"

	Square::Square(int number) : number(number) {
		setRow();
		setColumn();
		setColor();
		resetFeatures();
	}

	Square::~Square() {
	}

	void Square::setColor() {
		defaultForegroundColor = even(row) ?
			even(column) ? "BLACK" : "WHITE"
			: even(column) ? "WHITE" : "BLACK";
		defaultBackgroundColor = defaultForegroundColor == "WHITE" ? "BLACK" : "WHITE";
	}

	void Square::setColumn() {
		column = (number % BOARD_WIDTH);
	}

	void Square::setRow() {
		row = number / 8;
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

	bool Square::hasPiece() {
		return piece != EMPTY_SPACE;
	}
#endif