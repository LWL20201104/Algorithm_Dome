/*
* @Author: lwl
* @Date: 2019-12-22
* @Description: ����һ����N*M�����;���matrix��һ������K��matrix��ÿһ�к�ÿһ �ж����ź���ġ�
*               ʵ��һ���������ж�K�Ƿ���matrix�У�ʱ�临�Ӷ�ΪO(N+M)������ռ临�Ӷ�ΪO(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class CFindNum {
public:
	bool isComtainsUpToDown(vector<vector<int> >& mat, int k) {
		int r = 0;
		int c = mat.at(0).size() - 1;
		while (r <= (mat.size() - 1) && c >= 0) {
			if (mat.at(r).at(c) > k) {
				c--;
			}
			else if (mat.at(r).at(c) < k) {
				r++;
			}
			else {
				return true;
			}
		}
		return false;
	}
};

class CComparator {
private:
	int k;
	vector<vector<int> > mat;
	CFindNum findNum;

private:
	void generalMatrix() {
		int arr1[4] = { 0, 1, 2, 5 };
		int arr2[4] = { 2, 3, 4, 7 };
		int arr3[4] = { 4, 4, 4, 8 };
		int arr4[4] = { 6, 7, 7, 9 };
		vector<int> r1(arr1, arr1 + 4);
		vector<int> r2(arr2, arr2 + 4);
		vector<int> r3(arr3, arr3 + 4);
		vector<int> r4(arr4, arr4 + 4);
		mat.push_back(r1);
		mat.push_back(r2);
		mat.push_back(r3);
		mat.push_back(r4);
	}

public:
	CComparator(int num) :
		k(num)
	{ }

	void runComparator() {
		generalMatrix();
		bool res = findNum.isComtainsUpToDown(mat, k);
		cout << (res ? "is contains" : "no contains") << endl;
	}
};

int main() {
	int k = 6;
	CComparator comparator(k);
	comparator.runComparator();
	system("pause");
	return 0;
}