#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct entry {
	int p;			/* ͼ�е�λ�� */
	int deep;		/* bfs ��� */
} entry;

class Egalitarianism {
private:
	vector <string> isFriend;
	vector <int> total;
	vector <bool> visited;
	bool dfs();
	int bfs(int p);
public:
	int maxDifference(vector <string> isFriend, int d);
};

/**
 * �ж��Ƿ���ǿ��ͨͼ
 */
bool Egalitarianism::dfs()
{
	stack <int> S;
	bool flag = true;
	S.push(0);
	while (!S.empty()) {
		int p = S.top();
		visited[p] = true;
		flag = true;
		for (int i = 0; i < isFriend.size(); i++) {
			if (!visited[i] && 'Y' == isFriend[p][i]) {
				visited[i] = true;
				S.push(i);
				flag = false;
				break;
			}
		}
		if (flag) {
			S.pop();
		}
	}
	for (int i = 0; i < isFriend.size(); i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

/**
 * ����p��ʾ�ӵ�p���˿�ʼ����������ֵΪͼ(��Ȩͼ)�и��㵽p����С�����е����ֵ
 */
int Egalitarianism::bfs(int p)
{
	queue < entry > Q;
	vector <int> total(isFriend.size());
	entry en;
	int md;

	for (int i = 0; i < isFriend.size(); i++) {
		total[i] = 0;
	}

	en.p = p;
	en.deep = 0;
	visited[p] = true;
	Q.push(en);
	while ( !Q.empty() ) {
		entry cus_p = Q.front();
		entry next_p = cus_p;
		Q.pop();
		++next_p.deep;
		for (int i = 0; i < isFriend.size(); i++) {
			if ( !visited[i] && 'Y' == isFriend[cus_p.p][i] ) {
				visited[i] = true;
				next_p.p = i;
				Q.push(next_p);
				total[i] = next_p.deep;
			}
		}
	}
	md = 0;
	for (int i = 0; i < isFriend.size(); i++) {
		if (total[i] > md) {
			md = total[i];
		}
	}
	return md;
}

int Egalitarianism::maxDifference(vector<string> isFriend, int d)
{
	this->isFriend = isFriend;
	int num = this->isFriend.size();
	int ans;
	for (int i = 0; i < num; i++) {
		visited.push_back(false);
	}
	if ( !dfs() ) {
		return -1;
	}

	ans = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			visited[j] = false;
		}
		ans = max(ans, bfs(i));
	}

	return ans * d;
}

/* ���� */
int main()
{
	string s[] = 	{"NYYN", "YNYN", "YYNN", "NNNN"};

	Egalitarianism E;
	vector <string> ss;
	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
		ss.push_back(s[i]);
	}
	int d = 1;
	cout << E.maxDifference(ss, d) << endl;

	return 0;
}