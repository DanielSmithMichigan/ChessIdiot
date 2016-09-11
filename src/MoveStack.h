#ifndef MoveStack_h
#define MoveStack_h
	#include "globals.h"
	#include <stdint.h>
	#define MOVE_STACK_LIMIT 512
	#define DEPTH_LIMIT 24

	class MoveStack {
		private:
			int depthLimits[DEPTH_LIMIT];
			int currentDepth = 0;
		protected:
		public:
			int top = 0;
			uint32_t stack[MOVE_STACK_LIMIT];
			void push(uint32_t move);
			void reset();
			void increaseDepth();
			void decreaseDepth();
			MoveStack();
			~MoveStack();
	};
#endif