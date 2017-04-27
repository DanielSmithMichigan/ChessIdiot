#ifndef State_h
#define State_h
	#include <stdint.h>
	struct State {
		uint32_t move;
		State* prev;
	};
#endif

