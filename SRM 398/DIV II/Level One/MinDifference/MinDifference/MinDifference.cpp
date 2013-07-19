#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>

using namespace std;

// split, auto generated by FileEdit
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
	if ( delim.find( s[i] ) != string::npos ) {
	    if ( !t.empty() ) {
		res.push_back( t );
		t = "";
	    }
	} else {
	    t += s[i];
	}
    }
    if ( !t.empty() ) {
	res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
	res.push_back( atoi( tok[i].c_str() ) );
    return res;
}
// split, auto generated by FileEdit

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

/************** Program  Begin *********************/
int Alist[10000];
class MinDifference {
public:
    int closestElements(int A0, int X, int Y, int M, int n) {
	Alist[0] = A0;
	for (int i = 1; i < n; i++) {
		Alist[i] = (Alist[i-1] * X + Y) % M;
	}

	int mind = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ( abs(Alist[i] - Alist[j]) < mind ) {
				mind = abs(Alist[i] - Alist[j]);
			}
		}
	}

	return mind;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	MinDifference theObject;
	eq(0, theObject.closestElements(3, 7, 1, 101, 5),6);
    }
    {
	MinDifference theObject;
	eq(1, theObject.closestElements(3, 9, 8, 32, 8),0);
    }
    {
	MinDifference theObject;
	eq(2, theObject.closestElements(67, 13, 17, 4003, 23),14);
    }
    {
	MinDifference theObject;
	eq(3, theObject.closestElements(1, 1221, 3553, 9889, 11),275);
    }
    {
	MinDifference theObject;
	eq(4, theObject.closestElements(1, 1, 1, 2, 10000),0);
    }
    {
	MinDifference theObject;
	eq(5, theObject.closestElements(1567, 5003, 9661, 8929, 43),14);
    }
}
// END CUT HERE
