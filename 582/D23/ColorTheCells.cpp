#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class ColorTheCells
{
private:
	vector <int> dryingTime;	/* ��Ҫ�����ʱ��  */
	vector <long> dryedTime;	/* ���ø����ʱ�䣬0��ʾ��û��paint */
	vector <int> paint_order;	/* paint���ӵ�˳�� */
public:
	long calc(int seq);
	int minimalTime(vector <int> dryingTime);
};

#define MOVE_TIME 1L
#define PAINT_TIME 1L
#define INFINITY_TIME LONG_MAX 

/* �ο�Ueddy����ʵ�� */
int ColorTheCells::minimalTime(vector<int> dryingTime)
{
	int num = dryingTime.size();
	long minTime = INFINITY_TIME;
	int i, j;

	this->dryingTime = dryingTime;
	paint_order.clear();		/* paint ��˳�� */
	dryedTime.clear();

	for (i = 0; i < num; i++) {
		paint_order.push_back(i);
		dryedTime.push_back(0);
	}

	/* brute force��ö�����е������ѡ����Сʱ�� */
	do {
		for (i = 0; i < (1<<num); i++) {
			for (j = 0; j < num; j++) {
				dryedTime[j] = 0;
			}
			minTime = min(minTime, calc(i));
		}
	} while (next_permutation(paint_order.begin(), paint_order.end()));

	return minTime;
}

/**
 * seqΪһ�����У�0��ʾ�ڱ�paintλ�����paint, 1��ʾ���ұ�paint��paint��˳����
 * paint_orderָ����
 */
long ColorTheCells::calc(int seq)
{
	long time;			/* ����ʱ�� */
	int num = dryingTime.size();
	int paint_dir;			/* paint�����ڱ�paintλ����߻����ұ�paint */
	int cur_pos;			/* ��ǰλ�� */
	int paint_pos;			/* paintλ�ã����Ǳ�paint��λ�� */
	int bias;			/* �ӵ�ǰλ�������߻��������� */
	
	cur_pos = 0;
	time = 0;
	for (int i = 0; i < num; i++) {
		paint_dir = seq & 1;
		seq /= 2;
		paint_dir = paint_dir ? 1 : -1;
		paint_pos = paint_order[i] + paint_dir;
		if (paint_pos < 0 || paint_pos >= num) {	/* λ�ò��Ϸ� */
			return INFINITY_TIME;
		}

		bias = 1;			/* �ӵ�ǰλ�������� */
		if (cur_pos - paint_pos > 0) {	/* �ӵ�ǰλ�������� */
			bias = -1;
		}
		
		/* ��forѭ������paintλ�ã��м�������û�и���ĸ���Ҫ�ȴ� */
		for (; cur_pos != paint_pos; cur_pos += bias) {
			if (dryedTime[cur_pos+bias] > time) {	/* �ȴ����� */
				time = dryedTime[cur_pos+bias];
			}
			time += MOVE_TIME;		/* �ƶ�ʱ�� */
		}
		time += PAINT_TIME;		/* ����Ŀ�ĵأ�paintʱ�� */
		dryedTime[paint_order[i]] = time + dryingTime[paint_order[i]];	/* ���¸ø��Ӹ���ʱ��  */
	}

	return time;
}

int main()
{
	ColorTheCells color;
	vector <int> dryingTime;
	int dry[] = {35198, 26281, 72533, 91031, 44326, 43178, 80000};

	for (int i = 0; i < (int)( sizeof(dry)/sizeof(dry[0]) ); i++) {
		dryingTime.push_back(dry[i]);
	}

	cout << color.minimalTime(dryingTime) << endl;

	return 0;
}

/* Ueddy �Ĵ��� */
class ColorTheCells_Ueddy
{
public:
	int N;
	int inf;
	vector <int> p;
	vector <int> d;			/* dryedTime */
	vector <int> dryingTime;

	int calc (int b)
	{
		int t = 0;		/* time */
		int x = 0;		/* ��ǰλ�� */
		int f;			/* �����ˢ�����ұ�ˢ�ı�־ */
		int dx;			/* ������-1, ������1 */
		int nx;			/* nxΪ��һ��Ҫˢ��λ�� */
		for (int i = 0; i < N; i++) {
			f = b & 1;		/* b�����λ, 0��ʾ�����ˢ��1��ʾ���ұ�ˢ */
			b /= 2;			/* b = b / 2 */
			nx = p[i] + 1;		/* ���ұ�ˢ */
			if (0 == f) {
				nx = p[i] - 1;
			}
			if (nx < 0 || nx >= N) {
				return inf;
			}
			dx = 1;
			if (nx - x < 0) {
				dx = -1;
			}
			for (; x != nx; x += dx) {
				if (t < d[x + dx]) {
					t = d[x + dx];	
				}
				++t;
			}
			++t;		/* ˢ��ʱ��Ϊ1 */
			d[p[i]] = t + dryingTime[p[i]];
		}
		return t;
	}

	int minimalTime(vector <int> dryingTime)
	{
		inf = 100000000;
		int ans = inf;
		this->dryingTime = dryingTime;
		N = dryingTime.size();
		p.clear();
		d.clear();
		for (int i = 0; i < N; i++) {
			p.push_back(i);
			d.push_back(0);
		}
		do {
			for (int i = 0; i < (1 << N); i++) {
				for (int j = 0; j < N; j++) {
					d[j] = 0;
				}
				/* d[] Ϊ0 */
				ans = min(ans, calc(i));
			}
		} while (next_permutation(p.begin(), p.end()));

		return ans;
	}
};
