#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int xorOperation(int n, int start) {
		int result = 0;
		for (int i = 0; i < n; i++) {
			result ^= (start + 2 * i);
		}

		return result;
	}
};

int main(){
	Solution sol;
	int res = 0 ;
	res = sol.xorOperation(5, 0);
	cout << res << endl;
	res = sol.xorOperation(4, 3);
	cout << res << endl;
	res = sol.xorOperation(1, 7);
	cout << res << endl;
	res = sol.xorOperation(10, 5);
	cout << res << endl;

	return 0;
}
