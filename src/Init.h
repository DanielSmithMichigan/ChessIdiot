#ifndef Init_h
#define Init_h
	#include "BitBoard.h"
	#include "TranspositionTable.h"

	using namespace std;

	class Init {
		private:
			bool finished;
		protected:
		public:
			static Init *instance;
			Init();
			~Init();
			void execute(bool force = false);
			void reset();
	};



#endif