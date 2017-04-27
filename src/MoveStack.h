#ifndef MoveStack_h
#define MoveStack_h
	#include "Globals.h"
	#include "Board.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <algorithm>
	#define MOVE_STACK_LIMIT 512
	#define DEPTH_LIMIT 24

	using namespace std;

	class MoveStack {
		private:
		protected:
		public:
			static int depthLimits[DEPTH_LIMIT];
			static int currentDepth;
			static int top;
			static uint32_t stack[MOVE_STACK_LIMIT];
			static void push(uint32_t move);
			static uint32_t pop();
			static void reset();
			static void increaseDepth();
			static void decreaseDepth();
			static int getDepthBottom();
			static int getMovesRemaining();
			static void sortCurrentDepth();
			MoveStack();
			~MoveStack();
	};



#endif