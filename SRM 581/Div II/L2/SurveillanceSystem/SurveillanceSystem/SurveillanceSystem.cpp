#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

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
#include <cstring>

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

/************** Program  Begin *********************/
const int MAX = 50;
int flag[MAX];
class SurveillanceSystem {
public:
    string getContainerInfo(string containers, vector <int> reports, int L) {
	string res(containers.size(), '-');
	vector < vector<int> > pos( containers.size()+1 );	
				// pos[c]��ʾ�ܹ����ӵ�c��'X'�����е�λ�õ���ʼ��
	vector <int> rep_count( L+1 );	// rep_count[c]��ʾ��reports��c���ֵĴ���

	for (int i = 0; i <= containers.size()-L; i++) {
		int c = count(&containers[i], &containers[i]+L, 'X');	
				// �������λ���ܼ��ӵ���'X'
		pos[c].push_back(i);
	}
	for (int i = 0; i < reports.size(); i++) {
		++rep_count[ reports[i] ];
	}

	for (int i = 0; i <= L; i++) {
		int rc = rep_count[i];
		if (rc == 0) {
			continue;
		}

		// ��ʾi��reports�г���rc�Σ���������Լ��ӵ�i��'X'�Ķα�����pos[i]�У�
		// һ����pos[i].size�������ĶΣ�Ҳ����Ҫ����ѡ��rc���Σ�ʹ��ÿ��λ�õ�
		// �ص������жϸ�λ���Ƿ�һ���ᱻ���ӵ���λ�õ��ص��ȱ�ʾ��λ����
		// pos[i].size�����г��ֵĴ������������ִ�������pos[i].size-rc����
		// ���λ��һ���ᱻ���ӵ�����Ϊ������λ��û�б����ӵĻ�����ô�Ҳ�����
		// ������rc���Ρ�
		memset(flag, 0, sizeof(flag));
		for (int j = 0; j < pos[i].size(); j++) {
			for (int k = 0; k < L; k++) {
				if ('-' == res[ pos[i][j] + k ]) {
					// �ڶ��г��ֵ�λ����Ϊ'?'
					res[ pos[i][j] + k ] = '?';
				}
				++flag[ pos[i][j]+k ];	// ��λ���ص��ȼ�1
			}
		}
		for (int j = 0; j < containers.size(); j++) {
			if (flag[j] > pos[i].size() - rc) {	
					//�ж��ص��ȣ��жϸ�λ���Ƿ�ض�������
				res[j] = '+';
			}
		}
	}

	return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int reportsARRAY[] = {1};
	vector <int> reports( reportsARRAY, reportsARRAY+ARRSIZE(reportsARRAY) );
	SurveillanceSystem theObject;
	eq(0, theObject.getContainerInfo("X", reports, 1),"+");
    }
    {
	int reportsARRAY[] = {2};
	vector <int> reports( reportsARRAY, reportsARRAY+ARRSIZE(reportsARRAY) );
	SurveillanceSystem theObject;
	eq(1, theObject.getContainerInfo("-XXXXX-", reports, 3),"???-???");
    }
    {
	int reportsARRAY[] = {3, 0, 2, 0};
	vector <int> reports( reportsARRAY, reportsARRAY+ARRSIZE(reportsARRAY) );
	SurveillanceSystem theObject;
	eq(2, theObject.getContainerInfo("------X-XX-", reports, 5),"++++++++++?");
    }
    {
	int reportsARRAY[] = {2, 1, 0, 1};
	vector <int> reports( reportsARRAY, reportsARRAY+ARRSIZE(reportsARRAY) );
	SurveillanceSystem theObject;
	eq(3, theObject.getContainerInfo("-XXXXX---X--", reports, 3),"???-??++++??");
    }
    {
	int reportsARRAY[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	vector <int> reports( reportsARRAY, reportsARRAY+ARRSIZE(reportsARRAY) );
	SurveillanceSystem theObject;
	eq(4, theObject.getContainerInfo("-XX--X-XX-X-X--X---XX-X---XXXX-----X", reports, 7),"???++++?++++++++++++++++++++??????--");
    }
}
// END CUT HERE
