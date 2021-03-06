/*
*@Author: lwl
*@Date: 2019-12-16
*@Description: 利用桶排序的思想，计算一个数组排序后，相邻两数的最大差值，要求时间复杂度O(N)，空间复杂度O(N)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

class CGetMaxGap {
private:
	int getBucketNum(int val, int min, int max, int len) {
		return static_cast<int>((val - min) * len / (max - min));
	}
	
public:
	int getMaxGap(vector<int>& vec) {
		int maxGap = 0;
		if (vec.size() <= 1) {
			return maxGap;
		}
		int len = vec.size();
		int maxVal = INT_MIN;
		int minVal = INT_MAX;
		for (int i : vec) {
			maxVal = maxVal < i ? i : maxVal;
			minVal = minVal > i ? i : minVal;
		}
		if (minVal == maxVal) {
			return maxGap;
		}
		vector<bool> hasNum(len + 1);
		for (int i = 0; i <= len; ++i) {
			hasNum.at(i) = false;
		}
		vector<int> max(len + 1);
		vector<int> min(len + 1);
		max.at(len) = maxVal;
		min.at(len) = maxVal;
		hasNum.at(len) = true;
		max.at(0) = minVal;
		min.at(0) = minVal;
		hasNum.at(0) = true;
		for (int i : vec) {
			int bucketNum = getBucketNum(i, minVal, maxVal, len);
			max.at(bucketNum) = hasNum.at(bucketNum) == true ? (max.at(bucketNum) > i ? max.at(bucketNum) : i) : i;
			min.at(bucketNum) = hasNum.at(bucketNum) == true ? (min.at(bucketNum) < i ? min.at(bucketNum) : i) : i;
			hasNum.at(bucketNum) = true;
		}
		int preMax = max.at(0);
		for (int i = 1; i <= len; ++i) {
			if (hasNum.at(i) == true) {
				maxGap = maxGap > (min.at(i) - preMax) ? maxGap : (min.at(i) - preMax);
				preMax = max.at(i);
			}
		}
		return maxGap;
	}
};

class CComparator : public CGetMaxGap {
private:
	int max;
	int size;
	int testTime;

private:
	void generalRandomArr(vector<int>& vec) {
		for (int i = 0; i < size; ++i) {
			vec.push_back(rand() % (max + 1));
		}
	}

	void print(vector<int>& vec) {
		for (int i : vec) {
			cout << i << " ";
		}
		cout << endl;
	}

	bool isEqual(int res, int copyRes) {
		return res == copyRes;
	}

	int rightMethod(vector<int>& vec) {
		if (vec.size() <= 1) {
			return 0;
		}
		sort(vec.begin(), vec.end());
		int max = 0;
		for (size_t i = 1; i < vec.size(); ++i) {
			max = max >= (vec.at(i) - vec.at(i - 1)) ? max : (vec.at(i) - vec.at(i - 1));
		}
		return max;
	}

public:
	CComparator(int valueMax, int valueSize, int testTime) :
		max(valueMax),
		size(valueSize),
		testTime(testTime)
	{ srand(time(0)); }

	void runComparator() {
		bool success = true;
		while (testTime--) {
			vector<int> arr;
			generalRandomArr(arr);
			vector<int> copyArr = arr;
			int max = getMaxGap(arr);
			int copyMax = rightMethod(copyArr);
			bool res = isEqual(max, copyMax);
			if (res == false) {
				res = false;
			}
			success = success && isEqual(max, copyMax);
		}
		cout << (success ? "nice" : "false") << endl;
	}
};

int main() {
	int valueMax = 100;
	int testTime = 500000;
	int valueSize = 100;
	CComparator comparator(valueMax, valueSize, testTime);
	comparator.runComparator();
	system("pause");
	return 0;
}