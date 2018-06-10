#ifndef ConstructUci_cpp
#define ConstructUci_cpp
	#include "ConstructUci.h"

	vector<string> commands = {"isready", "position", "fen", "uci", "go"};

	ConstructUci *ConstructUci::instance = new ConstructUci();


	ConstructUci::ConstructUci() {

	}

	ConstructUci::~ConstructUci() {

	}

	void ConstructUci::fromArgv(int argc, char** argv) {
		vector<string> input;
		for (int i = 1; i < argc; i++) {
			if (find(commands.begin(), commands.end(), argv[i]) != commands.end()
				and !input.empty()) {
				Uci::instance->readLine(boost::algorithm::join(input, " "));
				input.clear();
			}
			input.push_back(string(argv[i]));
		}
		Uci::instance->readLine(boost::algorithm::join(input, " "));
	}
#endif