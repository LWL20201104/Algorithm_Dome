/*
* @Author: lwl
* @Date: 2020-01-05
* @Description: һ������г����룬����Ҫ���Ѻͳ�����ֵһ����ͭ��ģ�һȺ�������������������ô����ʡͭ�壿
*               ����һ����������������
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class CLessMoney {
private:
	priority_queue<int, vector<int>, greater<int>> pQ;

private:
	void generalHead(vector<int>& costs) {
		for (int cost : costs) {
			pQ.push(cost);
		}
	}

	void printHead() {
		while (!pQ.empty()) {
			cout << pQ.top() << " ";
			pQ.pop();
		}
	}

public:
	int lessMoney(vector<int>& costs) {
		generalHead(costs);
		int sum = 0;
		int preSum = 0;
		while (pQ.size() >= 2) {
			sum += pQ.top();
			pQ.pop();
			sum += pQ.top();
			pQ.pop();
			pQ.push(sum - preSum);
			preSum = sum;
		}
		return sum;
	}
};

class CTest {
private:
	CLessMoney money;

public:
	void runTest(vector<int>& costs) {
		cout << "less money is:  " << money.lessMoney(costs) << endl;
	}
};

int main() {
	vector<int> costs{ 10, 20, 30, 60 };
	CTest test;
	test.runTest(costs);
	system("pause");
	return 0;
}