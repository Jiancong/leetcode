#include <bits/stdc++.h>
using namespace std;

class Solution { 
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int count = 0;
		if ( startTime.size() != endTime.size() ) {
			return -1;
		}

		for (int i = 0; i < startTime.size(); i++) {
			if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
				count++;
			}	
		}
		return count;
	}
};

int TestCase1() {
	Solution sol;
	
	vector<int> startTime{9,8,7,6,5,4,3,2,1};
	vector<int> endTime{10,10,10,10,10,10,10,10,10};

	int queryTime = 5;

	int count = sol.busyStudent(startTime, endTime, queryTime);

	cout << "count:" << count << endl;

	return 0;
}

int main(){
	TestCase1();
	
	return 0;
}
