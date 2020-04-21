#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {

		int sum = 0;

		for (int j = 0; j < K; j++)
		{
			int min_index = 0;
			int min = 200;
			for (int i = 0; i < A.size(); i++)
			{
				if (A[i] < min) {
					min = A[i];
					min_index = i;
				}
			}
			
			A[min_index] = -A[min_index];
		}

		for (int i = 0; i < A.size();i++)
			sum += A[i];

		return sum;
    }
};

int main(){
	vector<int> res;
	//res.push_back(4);
	//res.push_back(2);
	//res.push_back(3);
	//int k = 1;
	//res.push_back(3);
	//res.push_back(-1);
	//res.push_back(0);
	//res.push_back(2);
	//int k = 3;
	res.push_back(2);
	res.push_back(-3);
	res.push_back(-1);
	res.push_back(5);
	res.push_back(-4);
	int k = 2;
	Solution sol;

	int min_sum = sol.largestSumAfterKNegations(res, k);
	cout << min_sum << endl;
	return 0;
}
