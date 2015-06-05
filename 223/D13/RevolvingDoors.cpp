/**
 * TopCoder:RevolvingDoors
 * ��http://community.topcoder.com/stat?c=problem_statement&pm=3064&rd=5869��
 * Author: xuzhezhao
 * E-mail: zhezhaoxu@gmail.com
 * Blog: http://blog.csdn.net/xuzhezhaozhao/
 * Date: 2013/6/7
 */

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

#define MAX 50			/* ��ͼ���������� */
#define DOORS_MAX 10		/* �������� */

class RevolvingDoors
{
public:
	int turns(vector <string> map);
};

enum Door_State {H, V};		/* �ŵ�״̬��H��ˮƽ V����ֱ */
typedef struct {
	int row;
	int col;
}pos_t;
typedef struct CurrentPos{
	int row;			/* ��ǰ������ */
	int col;			/* ��ǰ������ */
	Door_State door[MAX][MAX];	/* ��״̬���� */
	pos_t door_pos[DOORS_MAX];	/* ��λ����Ϣ */
	int doors_num;			/* ������ */
	int turn_doors;			/* trun�������� */
}CurrentPos;

static int map_rows = 0;	/* ��ͼ���� */
static int map_cols = 0;	/* ��ͼ���� */
static int end_row;		/* �յ��������� */
static int end_col;		/* �յ��������� */
static int visited[MAX][MAX];
int step = 0;

void init(vector <string> &map, CurrentPos &curpos);
bool isEnd(CurrentPos curpos);
bool isVisited(vector <CurrentPos> LV, CurrentPos curpos);

int main()
{
	RevolvingDoors revolvingdoors;
	
	vector <string> map;
	
	map.push_back(" |  |  |     |  |  |  |  |  | ");
	map.push_back(" O  O EO -O- O  O  O  O  OS O ");
	map.push_back(" |  |  |     |  |  |  |  |  | ");

	cout << revolvingdoors.turns(map) << endl;
	cout << step << endl;
	return 0;
}

int RevolvingDoors::turns(vector <string> map)
{
	queue <CurrentPos> LC;		/* LC: �ڲ�BFS״̬ */
	queue <CurrentPos> LD;		/* LD: ���BFS��turn ����֮���״̬ */
	vector <CurrentPos> LV;		/* LV�����BFS����״̬��־������visited���飬����turn����֮���״̬���Ա����ظ� */
	CurrentPos curpos, nextpos;
	int row, col;

	init(map, curpos);
	LD.push(curpos);

	/* ���BFS */
	while (!LD.empty()) {
		curpos = LD.front();
		LD.pop();

		/* ��ʼ��visited���� */
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				visited[i][j] = false;
			}
		}

		LC.push(curpos);

		/* �ڲ�BFS */
		while (!LC.empty()) {
			++step;
			curpos = LC.front();
			LC.pop();
			row = curpos.row;
			col = curpos.col;
			visited[row][col] = true;

			if (isEnd(curpos)) {
				return curpos.turn_doors;
			}

			/* ���������������ĸ������ƽ�״̬ */

			/* ������ */
			nextpos = curpos;
			if (row - 1 >= 0 && !visited[row-1][col]) {
				nextpos.row = row - 1;

				if (' ' == map[row-1][col]) {
					LC.push(nextpos);
				} else if ('*' == map[row-1][col]) {	/* �����ŵ��������� */
					/* �ŵ�λ����������� */
					if (row - 2 >= 0 && 'O' == map[row-2][col] && H == curpos.door[row-2][col] ) {
						LC.push(nextpos);
					} else if (col + 1 <= map_cols - 1 && 
						'O' == map[row-1][col+1]) {
						if (V == curpos.door[row-1][col+1]) {
							LC.push(nextpos);
						} else {	/* turn door */
							nextpos.door[row-1][col+1] = V;
							++nextpos.turn_doors;
							visited[row-1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					} else if (col - 1 >= 0 && 'O' == map[row-1][col-1]) {
						if (V == curpos.door[row-1][col-1]) {
							LC.push(nextpos);
						} else {
							nextpos.door[row-1][col-1] = V;
							++nextpos.turn_doors;
							visited[row-1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					}
				}
			}

			/* ������ */
			nextpos = curpos;
			if (row + 1 <= map_rows - 1 && !visited[row+1][col]) {
				nextpos.row = row + 1;
				if (' ' == map[row+1][col]) {
					LC.push(nextpos);
				} else if ('*' == map[row+1][col]) {
					if (row + 2 <= map_rows - 1 && 'O' == map[row+2][col] &&
						H == curpos.door[row+2][col] ) {
						LC.push(nextpos);
					} else if (col + 1 <= map_cols - 1 && 'O' == map[row+1][col+1]) {
						if (V == curpos.door[row+1][col+1]) {
							LC.push(nextpos);
						} else {	/* turn door */
							nextpos.door[row+1][col+1] = V;
							++nextpos.turn_doors;
							visited[row+1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					} else if (col - 1 >= 0 &&
						'O' == map[row+1][col-1]) {
						if (V == curpos.door[row+1][col-1]) {
							LC.push(nextpos);
						} else {
							nextpos.door[row+1][col-1] = V;
							++nextpos.turn_doors;
							visited[row+1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					}
				}
			}

			/* ������ */
			nextpos = curpos;
			if (col - 1 >= 0 && !visited[row][col-1]) {
				nextpos.col = col - 1;
				if (' ' == map[row][col-1]) {
					LC.push(nextpos);
				} else if ('*' == map[row][col-1]) {
					if (col - 2 >= 0 && 'O' == map[row][col-2] &&
						V == curpos.door[row][col-2] ) {
						LC.push(nextpos);
					} else if (row - 1 >= 0 && 
						'O' == map[row-1][col-1]) {
						if (H == curpos.door[row-1][col-1]) {
							LC.push(nextpos);
						} else {	/* turn door */
							nextpos.door[row-1][col-1] = H;
							++nextpos.turn_doors;
							visited[row][col-1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					} else if (row + 1 <= map_rows - 1 && 'O' == map[row+1][col-1]) {
						if (H == curpos.door[row+1][col-1]) {
							LC.push(nextpos);
						} else {
							nextpos.door[row+1][col-1] = H;
							++nextpos.turn_doors;
							visited[row][col-1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					}
				}
			}

			/* ������ */
			nextpos = curpos;
			if (col + 1 <= map_cols - 1 && !visited[row][col+1]) {
				nextpos.col = col + 1;
				if (' ' == map[row][col+1]) {
					LC.push(nextpos);
				} else if ('*' == map[row][col+1]) {
					if (col + 2 <= map_cols - 1 && 'O' == map[row][col+2] &&
						V == curpos.door[row][col+2] ) {
							LC.push(nextpos);
					} else if (row + 1 <= map_rows - 1 && 
						'O' == map[row+1][col+1]) {
						if (H == curpos.door[row+1][col+1]) {
							LC.push(nextpos);
						} else {	/* turn door */
							nextpos.door[row+1][col+1] = H;
							++nextpos.turn_doors;
							visited[row][col+1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					} else if (row - 1 >= 0 &&
						'O' == map[row-1][col+1]) {
						if (H == curpos.door[row-1][col+1]) {
							LC.push(nextpos);
						} else {
							nextpos.door[row-1][col+1] = H;
							++nextpos.turn_doors;
							visited[row][col+1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					}
				}
			}
		}
	}
	return -1;
}

/**
 * ��ʼ��������õ�ͼ�Ļ�����Ϣ���У��У���״̬�����������ܵ�4������Ϊ '*' �ַ����� S�� E ��Ϊ' '(�ո�)��
 */
void init(vector <string> &map, CurrentPos &curpos)
{
	int i, j;
	
	curpos.turn_doors = 0;

	map_rows = map.size();

	if (map_rows > 0) {
		map_cols = map[0].length();
	}

	for (i = 0; i < map_rows; i ++) {
		for (j = 0; j < map_cols; j++) {
			if ('S' == map[i][j]) {
				curpos.row = i;
				curpos.col = j;
				map[i][j] = ' ';
			}
			if ('E' == map[i][j]) {
				end_row = i;
				end_col = j;
				map[i][j] = ' ';
			}
		}
	}
	curpos.doors_num = 0;
	for (i = 0; i < map_rows; i ++) {
		for (j = 0; j < map_cols; j++) {
			if ('O' == map[i][j]) {
				curpos.door_pos[curpos.doors_num].row = i;
				curpos.door_pos[curpos.doors_num].col = j;
				++curpos.doors_num;
				if ('|' == map[i+1][j]) {
					curpos.door[i][j] = V;
				} else {
					curpos.door[i][j] = H;
				}
				map[i+1][j] = map[i-1][j] =
					map [i][j+1] = map[i][j-1] = '*';
			}
		}
	}
}

/**
 * �ж��Ƿ񵽴��յ�
 */
bool isEnd(CurrentPos curpos)
{
	if (curpos.row == end_row && curpos.col == end_col) {
		return true;
	} else {
		return false;
	}
}

/**
 * ���BFS���ʱ�־����LV�к���curpos״̬������true�����򷵻�false
 */
bool isVisited(vector <CurrentPos> LV, CurrentPos curpos)
{

	int door_row, door_col;
	bool flag;
	if (LV.empty()) {
		return false;
	}
	for (int i = 0; i < LV.size(); i++) {
		if (LV[i].row == curpos.row && LV[i].col == curpos.col) {
			flag = true;
			for (int j = 0; j < curpos.doors_num; j++) {
				door_row = curpos.door_pos[j].row;
				door_col = curpos.door_pos[j].col;
				if (LV[i].door[door_row][door_col] != curpos.door[door_row][door_col]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return true;
			}
		}
	}
	return false;
}