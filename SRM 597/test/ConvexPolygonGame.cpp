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

/*************** Program Begin **********************/

class ConvexPolygonGame {
public:
    string winner(vector <int> X, vector <int> Y) {
        string res;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int XARRAY[] = {0, 1, 0};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {0, 0, 1};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        ConvexPolygonGame theObject;
        eq(0, theObject.winner(X, Y),"Petya");
    }
    {
        int XARRAY[] = {0, 4, 2};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {0, 0, 2};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        ConvexPolygonGame theObject;
        eq(1, theObject.winner(X, Y),"Masha");
    }
    {
        int XARRAY[] = {0, 100, 100, 0};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {0, 0, 100, 100};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        ConvexPolygonGame theObject;
        eq(2, theObject.winner(X, Y),"Masha");
    }
    {
        int XARRAY[] = {0, 50, 100, 50};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {0, -1, 0, 1};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        ConvexPolygonGame theObject;
        eq(3, theObject.winner(X, Y),"Petya");
    }
    {
        int XARRAY[] = {-100000, 100000, 100000, -100000};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {-1, -1, 1, 1};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        ConvexPolygonGame theObject;
        eq(4, theObject.winner(X, Y),"Masha");
    }
}
// END CUT HERE
