#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
<<<<<<< HEAD
=======
	// 1281
>>>>>>> 815ca5c75078b9deeb2f2d646afc5013f5d47533
	int subtractProductAndSum(int n) {
		unsigned int product = 1;
		unsigned int sum = 0;
		while (n>0) {
			unsigned int p = n%10;
			n /= 10;
			product *= p;
			sum += p;
		}

		return (product - sum);
	}
<<<<<<< HEAD
}
=======
};
>>>>>>> 815ca5c75078b9deeb2f2d646afc5013f5d47533

void TestCase_1(Solution& sol) {
	cout << "result:" << sol.subtractProductAndSum(4421) << endl;
}

int main(){
	Solution sol;
	TestCase_1(sol);
}
