/*
*@Author: lwl
*@Date: 2019-12-18
*@Description: �� n*n �ľ�����ת 90��
*              ���ɣ���תȦ��ӡ˼����һ���ģ����ǴӾ�������忼�ǣ���Ҫ�����ھֲ���һȦһȦ����ת
*/

#include <iostream>
#include <vector>

using namespace std;

class CRotateMatrix {
private:
	void rotate(vector<vector<int> >& vec, int topR, int topC, int downR, int downC) {
		int time = 0;
		while ((topC + time) < downC && (topR + time) < downR) {
			int tmp = vec.at(downR - time).at(topC);
			vec.at(downR - time).at(topC) = vec.at(downR).at(downC - time);
			vec.at(downR).at(downC - time) = vec.at(topR + time).at(downC);
			vec.at(topR + time).at(downC) = vec.at(topR).at(topC + time);
			vec.at(topR).at(topC + time++) = tmp;
		}
	}

public:
	void rotateMatrix(vector<vector<int> >& vec) {
		int topR = 0;
		int topC = 0;
		int downR = vec.size() - 1;
		int downC = vec.at(0).size() - 1;
		while (topR < downR && topC < downC) {
			rotate(vec, topR++, topC++, downR--, downC--);
		}
	}
};

class CTest {
private:
	vector<vector<int> > vec;

public:
	void generalMatrix() {
		vector<int> vec1, vec2, vec3, vec4;
		vec.push_back(vec1);
		vec.push_back(vec2);
		vec.push_back(vec3);
		vec.push_back(vec4);
		for (int i = 1; i <= 4; ++i) {
			vec.at(0).push_back(i);
			vec.at(1).push_back(i + 4);
			vec.at(2).push_back(i + 8);
			vec.at(3).push_back(i + 12);
		}
	}

	void printMat() {
		for (size_t i = 0; i < vec.size(); ++i) {
			for (size_t j = 0; j < vec.at(0).size(); ++j) {
				cout << vec.at(i).at(j) << " ";
			}
			cout << endl;
		}
	}

public:
	void runTest() {
		generalMatrix();
		printMat();
		CRotateMatrix rotateMat;
		rotateMat.rotateMatrix(vec);
		cout << endl;
		printMat();
	}
};

int main() {
	CTest test;
	test.runTest();
	system("pause");
	return 0;
}