#ifndef TestUtilities_h
#define TestUtilities_h
	#include "../src/Move.h"
	#include <string>
	#include <vector>
	#include <algorithm>
	#include "gtest/gtest.h"

	using namespace std;

	bool sortByFrom (int i,int j);
	bool sortByTo (int i,int j);
	bool sortByPromotion (int i, int j);
	void assertStringVectorMatch (vector<string> &a, vector<string> &b);
#endif