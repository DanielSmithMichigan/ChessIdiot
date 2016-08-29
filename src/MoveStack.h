#ifndef MoveStack_h
#define MoveStack_h
	#include "globals.h"
	#include <stdint.h>

	class MoveStack {
		private:
			uint32_t stack[MOVE_STACK_LIMIT];
			int depthLimits[MAX_DEPTH];
			int top = 0;
			int currentDepth = 0;
		protected:
		public:
			void push(uint32_t move);
			void increaseDepth();
			void decreaseDepth();
			MoveStack();
			~MoveStack();
	};
#endif