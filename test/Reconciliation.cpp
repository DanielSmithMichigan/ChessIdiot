	#include "Reconciliation.h"

	Reconciliation::Reconciliation() {
		board.reset(new TestBoard());
		moveStack.reset(new TestMoveStack());
		attackedSquare.reset(new AttackedSquare(board));
		moveGenerationController.reset(new MoveGenerationController(board, moveStack, attackedSquare));
		fen.reset(new Fen(board));
	}

	Reconciliation::~Reconciliation() {
	}

	TEST_F(Reconciliation, StartingPosition) {
		ifstream infile("../test/Reconciliation/startingPosition");
		string fenStr;
		getline(infile, fenStr);
		fen->import(fenStr);
		vector<string> comparisonFens, myFens;
		while (getline(infile, fenStr)) {
			comparisonFens.push_back(fenStr);
		}
		moveGenerationController->generateAllMoves();
		uint32_t currentMove;
		while (currentMove = moveStack->pop()) {
			board->doMove(currentMove);
			myFens.push_back(fen->exportLegacyBoard());
			board->undoMove();
		}
		assertStringVectorMatch(comparisonFens, myFens);
	}