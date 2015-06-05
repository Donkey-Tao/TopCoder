#include <iostream>

using namespace std;

class WaiterTipping
{
public:
	int maxPercent(int total, int taxPercent, int money);
};

int WaiterTipping::maxPercent(int total, int taxPercent, int money)
{
	int res = money - ( total + total * taxPercent / 100 );
	int tip;
	if (res >= 0) {
		tip = res * 100 / total;

		/* �ؼ������٣�����õ���tip���ܲ������ֵ�����Ǳ����ֵС1��ֵ */
		if (total + total * taxPercent / 100 + (tip + 1) * total / 100 <= money) {
			++tip;
		}

		return tip;
	}
	return -1;
}

int main()
{
	WaiterTipping W;

	cout << W.maxPercent(100, 10, 1000) << endl;
}