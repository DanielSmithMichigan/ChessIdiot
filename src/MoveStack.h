#ifndef MoveStack_h
#define MoveStack_h
	#include "Globals.h"
	#include "Board.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <algorithm>
	#define MOVE_STACK_LIMIT 512
	#define DEPTH_LIMIT 100

	using namespace std;

	struct WeightedMove {
		uint32_t move;
		int score;
		WeightedMove(uint32_t move, int score) : move(move), score(score) {

		}
		WeightedMove() {
		}
	};

	class MoveStack {
		private:
			WeightedMove stack[MOVE_STACK_LIMIT];
			uint32_t depthLimits[DEPTH_LIMIT];
			uint32_t searchKillers[DEPTH_LIMIT][2];
			uint32_t top;
			uint32_t getDepthBottom();
		protected:
		public:
			uint32_t currentDepth;
			void reset();
			void push(uint32_t move);
			uint32_t pop();
			void increaseDepth();
			void decreaseDepth();
			void scoreSpecialMoves(uint32_t move);
			void markKiller(uint32_t move);
			static MoveStack *instance;
			MoveStack();
			~MoveStack();
	};



#endif