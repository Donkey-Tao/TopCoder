#include <iostream>
#include <list>
#include <string>

using namespace std;

class SmartWordToy
{
public:
	int minPresses(string start, string finish, string forbid[]);
};

typedef struct {
	string str;
	int steps;
}Button;

bool isForbid(string test, string forbid[]);
char nextChar(char ch);
char preChar(char ch);

int main()
{
	SmartWordToy toy;
	string start, finish;
	int steps;
	string forbid[] = {""};

	start = "aaaa";
	finish = "accc";
	steps = toy.minPresses(start, finish, forbid);

	cout << steps << endl;

	if (isForbid("aaaz", forbid)) {
		cout << "aaaz is forbid" << endl;
	}

	return 0;
}

int SmartWordToy::minPresses(string start, string finish, string forbid[])
{
	list <Button> List;
	Button button, button2;
	button.str = start;
	button.steps = 0;
	int steps = 0;
	
	List.push_back(button);
	while (button.str != finish && !List.empty()) {
		button = List.front();
		button2 = button;
		List.pop_front();
		steps++;
		++button2.steps;
		for (int i = 0; i < 4; i++) {
			button2.str = button.str;
			button2.str[i] = nextChar(button2.str[i]);
			if (!isForbid(button2.str, forbid)) {
				List.push_back(button2);
			}

			button2.str[i] = preChar(button2.str[i]);
			button2.str[i] = preChar(button2.str[i]);
			if (!isForbid(button2.str, forbid)) {
				List.push_back(button2);
			}
		}
	}

	if (button.str != finish) {
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
	int len;	/* forbid ���鳤�� */
	int pos1, pos2, pos3;
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