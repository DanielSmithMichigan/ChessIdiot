#ifndef MoveStack_h
#define MoveStack_h
	#include "globals.h"
	#include <stdint.h>
	#include <iostream>
	#define MOVE_STACK_LIMIT 512
	#define DEPTH_LIMIT 24

	using namespace std;

	class MoveStack {
		private:
			int depthLimits[DEPTH_LIMIT];
			int currentDepth;
		protected:
		public:
			int top;
			uint32_t stack[MOVE_STACK_LIMIT];
			void push(uint32_t move);
			uint32_t pop();
			void reset();
			void increaseDepth();
			void decreaseDepth();
			int getDepthBottom();
			int getMovesRemaining();
			MoveStack();
			~MoveStack();
	};
#endif