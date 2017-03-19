#ifndef TestUtilities_cpp
#define TestUtilities_cpp
	#include "testUtilities.h"
	bool sortByFrom (int i,int j) { return (FROM(i)<FROM(j)); }
	bool sortByTo (int i,int j) { return (TO(i)<TO(j)); }
	bool sortByPromotion (int i,int j) { return (PROMOTEDPIECE(i)<PROMOTEDPIECE(j)); }

	void assertStringVectorMatch(vector<string> &a, vector<string> &b) {
		while (a.size()) {
			string aElement = a.back();
			a.pop_back();
			vector<string>::iterator it;
			it = find (b.begin(), b.end(), aElement);
			if (it == b.end()) {
				cout << "NF: " << aElement << endl;
				ASSERT_NE(it, b.end());	
			}
			b.erase(it);
		}
		ASSERT_EQ(b.size(), 0);
	}

	void printMove(uint32_t move) {
		cout << "FROM: " << FROM(move) << endl;
		cout << "TO: " << TO(move) << endl;
	}
#endif