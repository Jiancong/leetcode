#include <bits/stdc++.h>
using namespace std;

#define PB push_back

typedef vector<int> vi;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

		int sum = 0;
		int m = mat.size();

		for (int i = 0; i < m; i++) {
			sum += mat[i][i] + mat[i][m-i-1];
		}

		if (m%2 == 1)
		{
			int n = m/2;
			sum -= mat[n][n];
		}

		return sum;
    }
};

int main() {

	Solution sol;
    vector<vi > matrix2d;
    vi v1,v2,v3;
    v1.PB(1);
    v1.PB(2);
    v1.PB(3);
    v2.PB(4);
    v2.PB(5);
    v2.PB(6);
    v3.PB(7);
    v3.PB(8);
    v3.PB(9);

    matrix2d.PB(v1);
    matrix2d.PB(v2);
    matrix2d.PB(v3);

	int ret = sol.diagonalSum(matrix2d);

	cout << ret << endl;   

	// solution comes here
	
	return 0;
}

