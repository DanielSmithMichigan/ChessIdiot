#ifndef TestBoard_h
#define TestBoard_h
	#include "../src/Board.h"
	#include "../src/utilities.h"

	using namespace std;

	class TestBoard : public Board {
		public:
			bool matches(int board[]);
			TestBoard();
			~TestBoard();
	};
#endif