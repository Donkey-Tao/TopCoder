/*
 *	TopCoder:  SmartWordToy (http://community.topcoder.com/stat?c=problem_statement&pm=3935&rd=6532)
 *	Author: xuzhezhao
 *	E-mail: zhezhaoxu@gmail.com
 *	Time: 2013/6/1
 */

#include <iostream>
#include <queue>
#include <string>

#define WORDS (26 * 26 * 26 * 26)	/* �����ܵ������ */

using namespace std;

class SmartWordToy
{
public:
	int minPresses(string start, string finish, string forbid[]);
};

typedef struct {
	string word;
	int steps;
}Button;

bool isForbid(string test, string forbid[]);
char nextChar(char ch);
char preChar(char ch);
int getWordIndex(string word);

bool visited[WORDS];			/* �����Ƿ񱻷��ʵı�־ */


int main()
{
	SmartWordToy toy;

	string start = "aaaa";
	string finish = "zzzz";
	string forbid[] = {""};

	/* ��ʼ��visited���� */
	for (int i = 0; i < WORDS; i++) {
		visited[i] = false;
	}

	cout << toy.minPresses(start, finish, forbid) << endl;

	return 0;
}

int SmartWordToy::minPresses(string start, string finish, string forbid[])
{
	queue <Button> Q;
	Button button, button_temp;
	
	if (isForbid(finish, forbid)) {
		return -1;
	}

	button.word = start;
	button.steps = 0;
	Q.push(button);
	while (button.word != finish && !Q.empty()) {
		button = Q.front();
		Q.pop();
		
		/* ÿ�ζ���4����������ѡ��ÿ����������ѡ�����ϻ����°� */
		for (int i = 0; i < 4; i++) {
			/* ���ϰ� */
			button_temp = button;
			button_temp.word[i] = nextChar(button_temp.word[i]);
			if (!visited[getWordIndex(button_temp.word)]) {
				visited[getWordIndex(button_temp.word)] = true;
				++button_temp.steps;
				if (!isForbid(button_temp.word, forbid)) {
					Q.push(button_temp);
				}
			}

			/* ���°� */
			button_temp = button;
			button_temp.word[i] = preChar(button_temp.word[i]);
			if (!visited[getWordIndex(button_temp.word)]) {
				visited[getWordIndex(button_temp.word)] = true;
				++button_temp.steps;
				if (!isForbid(button_temp.word, forbid)) {
					Q.push(button_temp);
				}
			}
		}
	}

	if (button.word != finish) {
		return -1;
	} else {
		return button.steps;
	}
}

/**
 * �ж�test�ַ����Ƿ�������forbid�������ַ���,
 * �Ƿ���true�����򷵻�false.
 */
bool isForbid(string test, string forbid[])
{
	int i;
	int len;			/* length of forbid  */
	int pos1, pos2, pos3;		/* white space positons */
	string s0, s1, s2, s3;
	
	len = 0;
	while ("" != forbid[len]) {
		++len;
	}

	/* ��forbid����Ϊ��ʱ������false */
	if (0 == len) {
		return false;
	}

	for (i = 0; i < len; i++) {
		pos1 = forbid[i].find_first_of(' ', 0);
		pos2 = forbid[i].find_first_of(' ', pos1 + 1);
		pos3 = forbid[i].find_first_of(' ', pos2 + 1);
		s0 = forbid[i].substr(0, pos1);
		s1 = forbid[i].substr(pos1 + 1, pos2 - pos1 - 1);
		s2 = forbid[i].substr(pos2 + 1, pos3 - pos2 - 1);
		s3 = forbid[i].substr(pos3 + 1, forbid[i].length() - pos3 - 1);

		/* �����forbid�ַ������򷵻�true */
		if (string::npos != s0.find_first_of(test[0], 0) &&
			string::npos != s1.find_first_of(test[1], 0) &&
			string::npos != s2.find_first_of(test[2], 0) &&
			string::npos != s3.find_first_of(test[3], 0)) {
			return true;
		}
	}

	/* ����forbid�ַ��� */
	return false;
}

/**
 * ��������ĸ����ch����һ���ַ�����ĸ��Ϊѭ���ģ���z����һ���ַ�Ϊa
 */
char nextChar(char ch)
{
	if ('z' == ch) {
		ch = 'a';
	} else {
		++ch;
	}
	return ch;
}

/**
 * ��������ĸ����ch����һ���ַ�����ĸ��Ϊѭ���ģ���a����һ���ַ�Ϊz
 */
char preChar(char ch)
{
	if ('a' == ch) {
		ch = 'z';
	} else {
		--ch;
	}
	return ch;
}

/**
 * ����ÿ�����ʵ���������ÿ�����ʿ���26��������a - z �ֱ��ʾ 0 - 25��
 * ���ʵ���ֵ��������ֵ��
 */
int getWordIndex(string word)
{
	return ((word[0] - 'a') * (26 * 26 * 26) + (word[1] - 'a') * (26 * 26) + 
		(word[2] - 'a') * 26 + (word[3] - 'a') );
}