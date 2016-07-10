#ifndef UbuntuScreen_cpp
#define UbuntuScreen_cpp
	#include "UbuntuScreen.h"

	UbuntuScreen::UbuntuScreen() {
		color["BLACK"] = "16";
		color["WHITE"] = "255";
	}

	UbuntuScreen::~UbuntuScreen() {
	}

	void UbuntuScreen::clear() {
		system("clear");
	}

	void UbuntuScreen::write(string value, string foregroundColor = "WHITE", string backgroundColor = "BLACK") {
		cout << "\033[38;5;" << color[foregroundColor] << ";48;5;" << color[backgroundColor] << "m" << value << "\033[m";
	}

	void UbuntuScreen::gotoxy(int x, int y) {
		printf("%c[%d;%df",0x1B,y,x);
	}
#endif