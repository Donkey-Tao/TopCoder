#include <iostream>
#include <string>
#include <vector>

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
#define MAX 51
int cnt[MAX];			// found��ÿ��Ԫ�س��ֵĴ���
long long Cr[MAX][MAX];		// Cr[n][m] ��ʾ��n��С����ѡm���Ĳ�ͬѡ��
vector < double > sels(MAX);	// ���Ľ����sels[K]����ĳ���Ҫ���ص�ֵ
vector < double > temp(MAX);	// ����ǰһ����������Ľ��

class Excavations2 {
public:
	long long count(vector <int> kind, vector <int> found, int K) 
	{	
		// �����Ƕ�ȫ�ֱ������г�ʼ��
		for (int i = 0; i < MAX; i++) {
			cnt[i] = 0;
			sels[i] = 0;
			temp[i] = 0;
			for (int j = 0; j < MAX; j++) {
				Cr[i][j] = 0;
			}
		}

		// �����Ǽ���Cr�����ֵ������Cr[n][r] = Cr[n-1][r] + Cr[n-1][r-1]
		Cr[0][0] = 1;
		for (int i = 1; i < MAX; i++) {
			Cr[i][0] = 1;
			Cr[i][i] = 1;
			for (int j = 1; j < i; j++) {
				Cr[i][j] = Cr[i-1][j] + Cr[i-1][j-1];
			}
		}

		// �����Ǽ���fonud��ÿ��Ԫ�س��ֵĴ��������������cnt������
		for (int i = 0; i < found.size(); i++) {
			cnt[i] = 0;
			for (int j = 0; j < kind.size(); j++) {
				if (found[i] == kind[j]) {
					++cnt[i];
				}
			}
		}
		
		// �����ǽ��ж�̬�滮��step�Ǳ�ʾֻ����found[step]��֮ǰ��Ԫ��
		for (int step = 0; step < found.size(); step++) {
			if (0 == step) {
				for (int i = 1; i <= cnt[step]; i++) {
					sels[i] = Cr[cnt[step]][i];
				}
				temp = sels;
			} else {
				for (int i = 0; i < MAX; i++) {
					sels[i] = 0;
				}
				for (int i = 1; i <= MAX; i++) {
					for (int j = 1; j <= MAX; j++) {
						if (i + j <= K) {
							sels[i+j] += temp[i] * Cr[cnt[step]][j];
						}
					}
				}
				temp = sels;
			}
		}

		return sels[K];
	}
};
/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int kindARRAY[] = {1, 2, 2, 1};
	vector <int> kind( kindARRAY, kindARRAY+ARRSIZE(kindARRAY) );
	int foundARRAY[] = {1};
	vector <int> found( foundARRAY, foundARRAY+ARRSIZE(foundARRAY) );
	Excavations2 theObject;
	eq(0, theObject.count(kind, found, 2), 1LL);
    }
    {
	int kindARRAY[] = {1, 2, 2, 1};
	vector <int> kind( kindARRAY, kindARRAY+ARRSIZE(kindARRAY) );
	int foundARRAY[] = {1, 2};
	vector <int> found( foundARRAY, foundARRAY+ARRSIZE(foundARRAY) );
	Excavations2 theObject;
	eq(1, theObject.count(kind, found, 2), 4LL);
    }
    {
	int kindARRAY[] = {1, 2, 1, 1, 2, 3, 4, 3, 2, 2};
	vector <int> kind( kindARRAY, kindARRAY+ARRSIZE(kindARRAY) );
	int foundARRAY[] = {4, 2};
	vector <int> found( foundARRAY, foundARRAY+ARRSIZE(foundARRAY) );
	Excavations2 theObject;
	eq(2, theObject.count(kind, found, 3), 6LL);
    }
    {
	int kindARRAY[] = {13, 6, 1, 13, 2, 6};
	vector <int> kind( kindARRAY, kindARRAY+ARRSIZE(kindARRAY) );
	int foundARRAY[] = {2, 6, 1, 13};
	vector <int> found( foundARRAY, foundARRAY+ARRSIZE(foundARRAY) );
	Excavations2 theObject;
	eq(3, theObject.count(kind, found, 5), 4LL);
    }
}
// END CUT HERE
