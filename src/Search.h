#ifndef Search_h
#define Search_h
	#include "Globals.h"
	#include "Board.h"
	#include "Fen.h"
	#include "MoveStack.h"
	#include "MoveGenerationController.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <algorithm>
	#define MOVE_STACK_LIMIT 512
	#define DEPTH_LIMIT 100

	using namespace std;

	class Search {
		private:
			uint32_t nodesSearched;
			uint32_t bestMove;
			int bestScore;
			int depthSearched;
			uint32_t getBestMove(int depth);
			void reset();
			int quiescence(int alpha, int beta);
			int alphaBeta(int alpha, int beta, int depthRemaining);
			void showStats();
			void showPv();
		protected:
		public:
			uint32_t iterativeDeepening(string fen, int maxDepth);
			static Search *instance;
			Search();
			~Search();
	};



#endif