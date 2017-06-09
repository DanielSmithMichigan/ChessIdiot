#ifndef Uci_h
#define Uci_h
	#include <thread>
	#include <iostream>
	#include <sstream>
	#include <string>
	#include <cmath>
	#include "Utility.h"
	#include "Init.h"
	#include "Fen.h"
	#include "Board.h"
	#include "Search.h"

	using namespace std;

	class Uci {
		private:
		protected:
		public:
			static Uci *instance;
			Uci();
			~Uci();
			void loop();
			void identify();
			void readyUp();
			void position(string input);
			void doMoves(string input);
			void doMove(string input);
			void go(string input);
			void getFen();
	};
#endif