#ifndef Square_cpp
#define Square_cpp
	#include "Square.h"

	Square::Square(int number) : number(number) {
		setColumn();
		setRow();
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
		column = number / 8 + 1;
	}

	void Square::setRow() {
		row = number % 8;
	}
#endif