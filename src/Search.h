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
	#include <cassert>
	#define MOVE_STACK_LIMIT 512
	#define DEPTH_LIMIT 100

	using namespace std;

	class Search {
		private:
			int stopTime;
			bool stopped;
			uint32_t nodesSearched;
			uint32_t bestMove;
			int bestScore;
			int depthSearched;
			void checkStopped();
			uint32_t getBestMove(int depth);
			void reset();
			int quiescence(int alpha, int beta);
			int alphaBeta(int alpha, int beta, int depthRemaining);
			void showStats();
			void showPv();
			bool isRepetition();
		protected:
		public:
			uint32_t iterativeDeepening(int maxDepth = DEPTH_LIMIT);
			void timeRemaining(int msRemaining);
			void clearForSearch();
			static Search *instance;
			Search();
			~Search();
	};



#endif