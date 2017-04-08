#ifndef MoveValue_h
#define MoveValue_h
	#include "Move.h"
	#include "Board.h"

	using namespace std;

	class MoveValue {
		private:
			shared_ptr<Board> board;
			int mvvLva[13][13];
			int pieceValue[13];
		protected:
		public:
			MoveValue(shared_ptr<Board> board);
			~MoveValue();
			void reset();
			int getValue(const uint32_t &move);
	};

#endif