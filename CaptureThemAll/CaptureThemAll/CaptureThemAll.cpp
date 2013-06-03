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

int getVexIndex(string cr);
vertex jump(vertex vex, int dirction);


int main()
{
	CaptureThemAll chess;
	string knight = "a1";
	string rook = "a8";
	string queen = "h1";

	cout << chess.fastKnight(knight, rook, queen) << endl;

	return 0;
}

int CaptureThemAll::fastKnight(string knight, string rook, string queen)
{
	queue<vertex> Q;
	vertex vex, vex_next;
	bool rook_eaten, queen_eaten;
	int knight_pos, rook_pos, queen_pos;
	rook_eaten = queen_eaten = false;
	knight_pos = getVexIndex(knight);
	rook_pos = getVexIndex(rook);
	queen_pos = getVexIndex(queen);

	vex.pos = knight_pos;
	vex.steps = 0;
	vex.queen_eaten = vex.rook_eaten = false;
	Q.push(vex);
	while (true) {
		vex = Q.front();
		Q.pop();
		for (int i = 1; i <= 8; i++) {
			vex_next = jump(vex, i);
			if (vex_next.pos > 0) {
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

/**
 * ����cr��ʾ������λ�õ�0��63���ֱ�ʾ��ʽ
 */
int getVexIndex(string cr)
{
	return (cr[0] - 'a') * COLS + (cr[1] - '1');
}

/**
 * 
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