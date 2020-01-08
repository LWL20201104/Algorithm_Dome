/*
* @Author: lwl
* @Date: 2020-01-08
* @Deacription: 1��ĸţÿ����һֻĸţ���³�����ĸţ�ɳ������Ҳ��ÿ����һֻĸţ�����費��������N���ĸţ������
*               2�����ÿֻĸţֻ�ܻ�10�꣬��N���ĸţ��������
*/

#include <iostream>

using namespace std;

class CCow {
public:
	int cowNoDead(int num) {
		if (num <= 0) {
			return 0;
		}
		if (num == 1 || num == 2 || num == 3) {
			return num;
		}
		else {
			return cowNoDead(num - 1) + cowNoDead(num - 3);
		}
	}

	int cowNoDeadOfUnrecur(int num) {
		if (num <= 0) {
			return 0;
		}
		if (num == 1 || num == 2 || num == 3) {
			return num;
		}
		else {
			int res = 0;
			int cur = 3;
			int pre = 2;
			int prepre = 1;
			for (int i = num; i >= 4; --i) {
				res = cur + prepre;
				prepre = pre;
				pre = cur;
				cur = res;
			}
			return res;
		}
	}

	int cowDead(int num) {
		if (num <= 1) {
			return 1;
		}
		else if (num == 2) {
			return 2;
		}
		else if (num == 3) {
			return 3;
		}
		else if (num > 10) {
			return cowDead(num - 1) + cowDead(num - 3) - cowDead(num - 10);
		}
		else {
			return cowDead(num - 1) + cowDead(num - 3);
		}
	}
};

int main() {
	CCow cow;
	int num = 20;
	int noDeadNum = cow.cowNoDead(num);
	cout << "if cow is not dead : " << noDeadNum << endl;
	int noDeadNumUnrecur = cow.cowNoDeadOfUnrecur(num);
	cout << "if cow is not dead : " << noDeadNumUnrecur << endl;
	int deadNum = cow.cowDead(num);
	cout << "if cow is dead : " << deadNum << endl;
	system("pause");
	return 0;
}