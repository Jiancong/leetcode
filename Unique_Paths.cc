#include <bits/stdc++.h>
using namespace std;

// Dynamic programming 
// memoriation

#define N 101

/*
 * Let NumberOfPaths(m, n) be the count of paths to reach row number m and column number n in the matrix,
 * */

class Solution {
public:
	Solution(){

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				NumberOfPaths[i][j] = 0;
			}
		}

		for (int i = 1; i < N; i++) {
			NumberOfPaths[1][i] = 1;
			NumberOfPaths[i][1] = 1;
		}

		for (int i = 2; i < N; i++) {
			for  (int j = 2; j < N; j++) {
				NumberOfPaths[i][j] = NumberOfPaths[i-1][j] + NumberOfPaths[i][j-1];
			}
		}
	}
	
    int uniquePaths(int m, int n) {
        return NumberOfPaths[m][n];
    }

private:
	unsigned int NumberOfPaths[N][N];
};

int main(){
	Solution sol;
	cout << sol.uniquePaths(3, 2) << endl;
	cout << sol.uniquePaths(7, 3) << endl;
	return 0;
}
