#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) {
	cerr << a;
}
static void print( long long a ) {
	cerr << a << "L";
}
static void print( string a ) {
	cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
	if( have.size() != need.size() ) {
		cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
		print( have );
		print( need );
		return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have );
			print( need );
			return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
// END CUT HERE

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

/*************** Program Begin **********************/

class MagicalGirlLevelTwoDivTwo {
public:
	string isReachable(vector <int> jumpTypes, int x, int y) {
		for (int i = 0; i < jumpTypes.size(); i++) {
			if (jumpTypes[i] % 2 == 0) {
				return "YES";
			}
		}
		return ((x + y) % 2 == 0 ? "YES" : "NO");
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int jumpTypesARRAY[] = {2};
		vector <int> jumpTypes( jumpTypesARRAY, jumpTypesARRAY+ARRSIZE(jumpTypesARRAY) );
		MagicalGirlLevelTwoDivTwo theObject;
		eq(0, theObject.isReachable(jumpTypes, 5, 4),"YES");
	}
	{
		int jumpTypesARRAY[] = {3};
		vector <int> jumpTypes( jumpTypesARRAY, jumpTypesARRAY+ARRSIZE(jumpTypesARRAY) );
		MagicalGirlLevelTwoDivTwo theObject;
		eq(1, theObject.isReachable(jumpTypes, 5, 4),"NO");
	}
	{
		int jumpTypesARRAY[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		vector <int> jumpTypes( jumpTypesARRAY, jumpTypesARRAY+ARRSIZE(jumpTypesARRAY) );
		MagicalGirlLevelTwoDivTwo theObject;
		eq(2, theObject.isReachable(jumpTypes, -30, 27),"YES");
	}
	{
		int jumpTypesARRAY[] = {29};
		vector <int> jumpTypes( jumpTypesARRAY, jumpTypesARRAY+ARRSIZE(jumpTypesARRAY) );
		MagicalGirlLevelTwoDivTwo theObject;
		eq(3, theObject.isReachable(jumpTypes, 29, 0),"NO");
	}
}
// END CUT HERE
