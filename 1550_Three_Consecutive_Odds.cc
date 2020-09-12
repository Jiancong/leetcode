#include <bits/stdc++.h>
using namespace std;

#define PB push_back

typedef vector<int> vi;

class Solution {
public:
	bool checkOdds(int a, int b, int c) {
		if (a%2==1 && b%2==1 && c%2==1)
			return true;
		else 
			return false;
	}

    bool threeConsecutiveOdds(vector<int>& arr) {

		bool retcode = false;

		if (arr.size() < 3 ) return false;

        for(int i=0; i < arr.size() - 2; i++) {
			retcode = checkOdds(arr[i], arr[i+1], arr[i+2]);	
			if (retcode == true)
				return retcode;
		}
		return retcode;
    }
};

int main() {

	vi v;
	v.PB(1);
	v.PB(2);
	v.PB(34);
	v.PB(3);
	v.PB(4);
	v.PB(5);
	v.PB(7);
	v.PB(23); 
	v.PB(12);

	// solution comes here
	Solution sol;
	bool ret=sol.threeConsecutiveOdds(v);
	cout << ret << endl;

	v.clear();
	v.PB(2);
	v.PB(6);
	v.PB(4);
	v.PB(1);
	ret=sol.threeConsecutiveOdds(v);
	cout << ret << endl;

	v.clear();
	v.PB(2);
	ret=sol.threeConsecutiveOdds(v);
	cout << ret << endl;
	return 0;
}

