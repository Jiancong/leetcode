
#include <bits/stdc++.h>
using namespace std;

#define PB push_back 

typedef vector<int > vi;

class Solution {
	public:
	int findLengthOfShortestSubarray(vector<int>& arr) {
		int m = 0;
		int n = 1;
		int deleted_cnt = 0;

		if (arr.size() <= 1) return 0;

		int length = arr.size();

		for (int i = 0; i < length-1; i++){
			if (arr[m] <= arr[n]) {
				n++;
				m++;
			} else {
				if ( m-1 < 0 ) {

					arr.erase(arr.begin()+m);
					deleted_cnt++;
				} else {
					int t = m-1;
					if ( arr[n] >= arr[t]) {
						arr.erase(arr.begin()+m);
						deleted_cnt++;
					} else {
						arr.erase(arr.begin()+n);
						deleted_cnt++;
					}
				}
			}
		}
		return deleted_cnt;
	}
};

int main() {

	vector<int> v; 
	v.PB(1);
	v.PB(2);
	v.PB(3);
	v.PB(10);
	v.PB(4);
	v.PB(2);
	v.PB(3);
	v.PB(5);

	Solution sol;

	int cnt = sol.findLengthOfShortestSubarray(v);
	cout << cnt << endl;

	v.clear();
	v.PB(5);
	v.PB(4);
	v.PB(3);
	v.PB(2);
	v.PB(1);

	cnt = sol.findLengthOfShortestSubarray(v);
	cout << cnt << endl;

	v.clear();
	v.PB(1);
	v.PB(2);
	v.PB(3);

	cnt = sol.findLengthOfShortestSubarray(v);
	cout << cnt << endl;

	v.clear();
	v.PB(1);

	cnt = sol.findLengthOfShortestSubarray(v);
	cout << cnt << endl;

	v.clear();
	v.PB(13);
	v.PB(0);
	v.PB(14);
	v.PB(7);
	v.PB(18);
	v.PB(18);
	v.PB(18);
	v.PB(16);
	v.PB(8);
	v.PB(15);
	v.PB(20);

	cnt = sol.findLengthOfShortestSubarray(v);
	cout << cnt << endl;

	return 0;
// solution comes here
}

