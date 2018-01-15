#ifndef ConstructUci_h
#define ConstructUci_h

	#include "Uci.h"
	#include <boost/algorithm/string/join.hpp>
	#include <algorithm>
	#include <vector>
	#include <iostream>
	#include <cstring>
	#include <string>

	using namespace std;

	class ConstructUci {
		private:
		protected:
		public:
			static ConstructUci *instance;
			ConstructUci();
			~ConstructUci();
			void fromArgv(int argc, char** argv);
	};
#endif