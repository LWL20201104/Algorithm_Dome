/*
* @Author: lwl
* @Date: 2020-01-06
* @Description: ����һ���ַ������͵�����strs���ҵ�һ��ƴ�ӷ�ʽ��ʹ�ð������ַ���ƴ����֮���γɵ��ַ���������͵��ֵ���
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class CLowestLexicographicalOrder {
private:
	void swap(vector<string>& arr, int n1, int n2) {
		string tmp = arr.at(n1);
		arr.at(n1) = arr.at(n2);
		arr.at(n2) = tmp;
	}

public:
	string getLowestLex(vector<string>& arr) {
		int len = arr.size();
		string res;
		if (len > 0) {
			for (int i = 1; i < len; ++i) {
				for (int j = i; j > 0; --j) {
					if ((arr.at(j - 1) + arr.at(j)) > (arr.at(j) + arr.at(j - 1))) {
						swap(arr, j - 1, j);
					}
					else {
						break;
					}
				}
			}
			vector<string>::iterator it = arr.begin();
			while (it != arr.end()) {
				res += *it++;
			}
		}
		return res;
	}
};

bool cmp(string str1, string str2) {
	return (str1 + str2) < (str2 + str1);
}

class CTest {
private:
	CLowestLexicographicalOrder lowestLex;
	
private:
	string rightMethod(vector<string>& arr) {
		string res;
		if (!arr.empty()) {
			sort(arr.begin(), arr.end(), cmp);
			vector<string>::iterator it = arr.begin();
			while (it != arr.end()) {
				res += *it++;
			}
		}
		return res;
	}

public:
	void runTest(vector<string>& arr) {
		vector<string> copyArr = arr;
		string res = rightMethod(arr);
		string copyRes = lowestLex.getLowestLex(copyArr);
		cout << "right method : " << res << endl;
		cout << "comarae method : " << copyRes << endl;
	}
};

int main() {
	vector<string> arr1{ string("jibw"), string("ji"), string("jp"), string("bw"), string("jibw") };
	vector<string> arr2{ string("ba"), string("b") };
	CTest test;
	test.runTest(arr1);
	system("pause");
	return 0;
}