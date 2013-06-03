/**
 * TopCoder: CaptureThemAll 
 *��http://community.topcoder.com/stat?c=problem_statement&pm=2915&rd=5853��
 * Author: xuzhezhao
 * E-mail: zhezhaoxu@gmail.com
 * Date: 2013/6/2
 */

#include <iostream>
#include <string>
#include <queue>

#define ROWS	8
#define COLS	8

#define STATES_NUM	(3 * ROWS * COLS)

using namespace std;

class CaptureThemAll
{
public:
	int fastKnight(string knight, string rook, string queen);
};

typedef struct {
	int pos;
	int steps;
	bool rook_eaten;
	bool queen_eaten;
}vertex;

int getPos(string cr);
vertex jump(vertex vex, int dirction);
int getStateIndex(vertex vex);

int visited[STATES_NUM];
int steps = 0;

int main()
{
	CaptureThemAll chess;
	string knight = "h8";
	string rook = "e2";
	string queen = "d2";

	for (int i = 0; i < STATES_NUM; i++) {
		visited[i] = false;
	}

	cout << chess.fastKnight(knight, rook, queen) << endl;
	cout << steps << endl;

	return 0;
}

int CaptureThemAll::fastKnight(string knight, string rook, string queen)
{
	queue<vertex> Q;
	int state;
	vertex vex, vex_next;
	bool rook_eaten, queen_eaten;
	int knight_pos, rook_pos, queen_pos;

	rook_eaten = queen_eaten = false;
	knight_pos = getPos(knight);
	rook_pos = getPos(rook);
	queen_pos = getPos(queen);

	vex.pos = knight_pos;
	vex.steps = 0;
	vex.queen_eaten = vex.rook_eaten = false;
	Q.push(vex);
	while (true) {
		vex = Q.front();
		Q.pop();
		steps++;
		for (int i = 1; i <= 8; i++) {
			vex_next = jump(vex, i);
			if (vex_next.pos > 0) {		/* û��Խ���̱߽� */
				state = getStateIndex(vex_next);
				if (!visited[state]) {
					visited[state] = true;
					if (vex_next.pos == rook_pos) {
						vex_next.rook_eaten = true;
					} else if (vex_next.pos == queen_pos) {
						vex_next.queen_eaten = true;
					}

					if (vex_next.rook_eaten && vex_next.queen_eaten) {
						return vex_next.steps;
					}

					Q.push(vex_next);
				}
			}
		}
	}
}

/**
 * ����cr��ʾ������λ�õ�0��63���ֱ�ʾ��ʽ
 */
int getPos(string cr)
{
	return (cr[0] - 'a') * COLS + (cr[1] - '1');
}

/**
 * �õ�knight��һ�����λ��
 */
vertex jump(vertex vex, int dirction)
{
	int col, row;
	col = vex.pos / COLS;	/* ��ܑ */
	row = vex.pos % ROWS;	/* ��ܑ */
	++vex.steps;
	switch (dirction) {
	case 1:		/* ��1��2 */
		col += 1;
		row += 2;
		break;
	case 2:		/* ��2��1 */
		col += 2;
		row += 1;
		break;
	case 3:		/* ��2��1 */
		col += 2;
		row -= 1;
		break;
	case 4:		/* ��1��2 */
		col += 1;
		row -= 2;
		break;
	case 5:		/* ��1��2 */
		col -= 1;
		row -= 2;
		break;
	case  6:	/* ��2��1 */
		col -= 2;
		row -= 1;
		break;
	case 7:		/* ��2��1 */
		col -= 2;
		row += 1;
		break;
	case 8:		/* ��1��2 */
		col -= 1;
		row += 2;
		break;
	}

	if (col > COLS - 1 || row > ROWS - 1 || col < 0 || row < 0) {
		vex.pos = -1;
	} else {
		vex.pos = col * COLS + row;
	}
	return vex;
}

/**
 * �õ���ǰλ�õ�״̬��������visited���飬ÿ������λ�ö�Ӧ��3��״̬��һ��û�гԵ�rook��
 * queen�����ǳԵ���rook��û�гԵ�queen�����ǳԵ���queen��û�гԵ�rook��
 */
int getStateIndex(vertex vex)
{
	if (!vex.rook_eaten && !vex.queen_eaten) {
		return (3 * vex.pos);
	} else if (vex.rook_eaten && !vex.queen_eaten) {
		return (3 * vex.pos + 1);
	} else {
		return (3 * vex.pos + 2);
	}
}