#ifndef Uci_cpp
#define Uci_cpp
	#include "Uci.h"

	Uci *Uci::instance = new Uci();


	Uci::Uci() {

	}

	Uci::~Uci() {

	}

	void Uci::loop() {
		string input;
		while (true) {
			if (!getline(cin, input)) {
				continue;
			}
			readLine(input);
		}
	}

	void Uci::readLine(string input) {
			string token = readToken(input);
			if (token == "uci") {
				identify();
			} else if (token == "isready") {
				readyUp();
			} else if (token == "position") {
				position(input);
			} else if (token == "go") {
				go(input);
			} else if (token == "fen") {
				getFen();
			}
	}

	void Uci::identify() {
		cout << "id name Merlin" << endl;
		cout << "id author Daniel Smith" << endl;
		cout << "uciok" << endl;
	}

	void Uci::readyUp() {
		Init::instance->execute();
		cout << "readyok" << endl;
	}

	void Uci::position(string input) {
		string positionCommand = readToken(input), position = "";
		if (positionCommand == "startpos") {
			Fen::import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		} else if (positionCommand == "fen") {
			for (int i = 0; i < 6; i++) {
				position = position + " " + readToken(input);
			}
			Fen::import(position);
		}

		if (readToken(input) == "moves") {
			doMoves(input);
		}
	}

	void Uci::doMoves(string input) {
		do {
			doMove(readToken(input));
		} while(input.length());
	}

	void Uci::doMove(string input) {
		int from = boardCoordToInt(input.substr(0, 2));
		int to = boardCoordToInt(input.substr(2, 2));
		int piece = 0;
		if (input.length() == 5) {
			piece = getPieceFromLetter(input.substr(4, 1));
		}
		MoveGenerationController::instance->generateAllMoves<false>();
		while (uint32_t currentMove = MoveStack::instance->pop()) {
			if (from == FROM(currentMove)
				&& to == TO(currentMove)
				&& piece == PIECE(currentMove)) {
				Board::doMove(currentMove);
				break;
			}
		}
		while (MoveStack::instance->pop()) {
		}
	}

	// go depth 6 wtime 180000 btime 100000 binc 1000 winc 1000 movetime 1000 movestogo 40
	void Uci::go(string input) {
		Init::instance->reset();
		while(input.length()) {
			string token = readToken(input);
			if (token == "wtime"
				&& Board::turn == WHITE) {
				Search::instance->timeRemaining(stoi(readToken(input)));
			} else if (token == "btime"
				&& Board::turn == BLACK) {
				Search::instance->timeRemaining(stoi(readToken(input)));
			}
		}
		uint32_t bestMove = Search::instance->iterativeDeepening(Fen::exportBoard());
		cout << "bestmove " << intToBoardCoord(FROM(bestMove)) << intToBoardCoord(TO(bestMove)) << endl;
	}

	void Uci::getFen() {
		cout << Fen::exportBoard() << endl;
	}
#endif