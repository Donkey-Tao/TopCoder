/*
 *	TopCoder:  WalkingHome
 *	Author: xuzhezhao
 *	E-mail: zhezhaoxu@gmail.com
 *	Blog: http://blog.csdn.net/xuzhezhaozhao
 *	Time: 2013/6/8
 */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class WalkingHome
{
public:
	int fewestCrossings(vector <string> map);
};

#define BUFFER_SIZE 100
#define ELEMENT_SIZE 50

typedef struct CurrentPos {
	int row;
	int col;
	int crossings;
}CurrentPos;

bool visited[ELEMENT_SIZE][ELEMENT_SIZE];	/* ���ʱ�־���� */
int map_rows;		/* ��ͼ���� */
int map_cols;		/* ��ͼ���� */

void init(vector <string> map, CurrentPos &curpos);

int main()
{
	WalkingHome walkinghome;
	vector <string> map;
	map.push_back("S-H");

	cout << walkinghome.fewestCrossings(map) << endl;

	return 0;
}

int WalkingHome::fewestCrossings(vector <string> map)
{
	queue <CurrentPos> QC, QS;
	CurrentPos curpos, nextpos;
	int row, col;

	init(map, curpos);

	/* ��ʼ��visited���� */
	for (int i = 0; i < ELEMENT_SIZE; i++) {
		for (int j = 0; j < ELEMENT_SIZE; j++) {
			visited[i][j] = false;
		}
	}

	QS.push(curpos);
	
	while (!QS.empty()) {
		curpos = QS.front();
		QS.pop();

		QC.push(curpos);
		while (!QC.empty()) {
			curpos = QC.front();
			QC.pop();	

			row = curpos.row;
			col = curpos.col;

			if ('H' == map[row][col]) {
				return curpos.crossings;
			}

			/* ���������ĸ����� */
			/* ������ */
			nextpos = curpos;
			if (row - 1 >= 0 && ('.' == map[row-1][col] || 'H' == map[row-1][col])) {
				if (!visited[row-1][col]) {
					nextpos.row = row - 1;
					visited[row-1][col] = true;
					QC.push(nextpos);
				}
			} else if (row - 1 >= 0 && '-' == map[row-1][col]) {
				int street_adj = 1; 
				while (row-1-street_adj >= 0 && '-' == map[row-1-street_adj][col]) {
					++street_adj;
				}
				if (row - 1 - street_adj >= 0 && ('.' == map[row-1-street_adj][col] || 'H' == map[row-1-street_adj][col])) {
					if (!visited[row-1-street_adj][col]) {
						visited[row-1-street_adj][col] = true;
						nextpos.row = row - 1 - street_adj;
						++nextpos.crossings;
						QS.push(nextpos);
					}
				}
			}
			/* ������ */
			nextpos = curpos;
			if (row + 1 <= map_rows-1 && ('.' == map[row+1][col] || 'H' == map[row+1][col])) {
				if (!visited[row+1][col]) {
					nextpos.row = row + 1;
					visited[row+1][col] = true;
					QC.push(nextpos);
				}
			} else if (row + 1 <= map_rows-1 && '-' == map[row+1][col]) {
				int street_adj = 1; 
				while (row+1+street_adj <= map_rows-1 && '-' == map[row+1+street_adj][col]) {
					++street_adj;
				}
				if (row + 1 + street_adj <= map_rows-1 && ('.' == map[row+1+street_adj][col] || 'H' == map[row+1+street_adj][col])) {
					if (!visited[row+1+street_adj][col]) {
						visited[row+1+street_adj][col] = true;
						nextpos.row = row + 1 + street_adj;
						++nextpos.crossings;
						QS.push(nextpos);
					}
				}
			}
			/* ������ */
			nextpos = curpos;
			if (col - 1 >= 0 && ('.' == map[row][col-1] || 'H' == map[row][col-1])) {
				if (!visited[row][col-1]) {
					nextpos.col = col - 1;
					visited[row][col-1] = true;
					QC.push(nextpos);
				}
			} else if (col - 1 >= 0 && '|' == map[row][col-1]) {
				int street_adj = 1; 
				while (col-1-street_adj >= 0 && '|' == map[row][col-1-street_adj]) {
					++street_adj;
				}
				if (col - 1 - street_adj >= 0 && ('.' == map[row][col-1-street_adj] || 'H' == map[row][col-1-street_adj])) {
					if (!visited[row][col-1-street_adj]) {
						visited[row][col-1-street_adj] = true;
						nextpos.col = col - 1 - street_adj;
						++nextpos.crossings;
						QS.push(nextpos);
					}
				}
			}
			/* ������ */
			nextpos = curpos;
			if (col + 1 <= map_cols-1 && ('.' == map[row][col+1] || 'H' == map[row][col+1])) {
				if (!visited[row][col+1]) {
					nextpos.col = col + 1;
					visited[row][col+1] = true;
					QC.push(nextpos);
				}
			} else if (col + 1 <= map_cols-1 && '|' == map[row][col+1]) {
				int street_adj = 1; 
				while (col+1+street_adj <= map_cols-1 && '|' == map[row][col+1+street_adj]) {
					++street_adj;
				}
				if (col + 1 + street_adj <= map_cols-1 && ('.' == map[row][col+1+street_adj] || 'H' == map[row][col+1+street_adj])) {
					if (!visited[row][col+1+street_adj]) {
						visited[row][col+1+street_adj] = true;
						nextpos.col = col + 1 + street_adj;
						++nextpos.crossings;
						QS.push(nextpos);
					}
				}
			}
		}
	}
	return -1;
}

/**
 * ��ʼ���������õ���ͼ�Ļ�����Ϣ
 */
void init(vector <string> map, CurrentPos &curpos)
{
	map_rows = map.size();
	map_cols = 0;

	map_cols = map[0].length();
	curpos.crossings = 0;
	for (int i = 0; i < map_rows; i++) {
		for (int j = 0; j < map_cols; j++) {
			if ('S' == map[i][j]) {
				curpos.row = i;
				curpos.col = j;
			}
		}
	}
}