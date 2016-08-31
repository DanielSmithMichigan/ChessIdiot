	#include "../src/KingMoveGenerator.h"
	#include "gtest/gtest.h"

	using namespace std;

	class KingMoveGeneratorTest {
		private:
			shared_ptr<KingMoveGenerator> kingMoveGenerator;
		public:
			KingMoveGeneratorTest();
			~KingMoveGeneratorTest();
			void run();
	};