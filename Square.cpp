#ifndef Square_cpp
#define Square_cpp
	#include "Square.h"

	Square::Square(int number) : number(number) {
		setRow();
		setColumn();
		setColor();
	}

	Square::~Square() {
	}

	void Square::setColor() {
		foregroundColor = even(row) ?
			even(column) ? "BLACK" : "WHITE"
			: even(column) ? "WHITE" : "BLACK";
		backgroundColor = foregroundColor == "WHITE" ? "BLACK" : "WHITE";
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
#endif