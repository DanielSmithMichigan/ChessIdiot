#ifndef TestUtilities_cpp
#define TestUtilities_cpp
	#include "testUtilities.h"
	bool sortByFrom (int i,int j) { return (FROM(i)<FROM(j)); }
	bool sortByTo (int i,int j) { return (TO(i)<TO(j)); }
	bool sortByPromotion (int i,int j) { return (PROMOTEDPIECE(i)<PROMOTEDPIECE(j)); }
#endif