
#include <bits/stdc++.h>

//your code here
//
using namespace std;

class Solution {
public:
	int max(int a, int b) {
		if (a>b) return a;
		else return b;
	}

	/*
	 *aGiven a binary array, find the maximum number of consecutive 1s in this array.
	
	 Example 1:
	Input: [1,1,0,1,1,1]
	Output: 3
	Explanation: The first two digits or the last three digits are consecutive 1s.
	    The maximum number of consecutive 1s is 3.
	Note:
	
	The input array will only contain 0 and 1.
	The length of input array is a positive integer and will not exceed 10,000
	 * */
    int findMaxConsecutiveOnes(vector<int>& nums) {
		int best = 0, sum = 0;
		for (int i=0; i < nums.size(); i++) {
			if (nums[i] > 0) sum += nums[i];
			else sum = 0;
			best = max(best, sum);
		}
		return best;
    }

	/*
	Given a positive integer num consisting only of digits 6 and 9.
	
	Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
	
	Example 1:
	
	Input: num = 9669
	Output: 9969
	Explanation: 
	Changing the first digit results in 6669.
	Changing the second digit results in 9969.
	Changing the third digit results in 9699.
	Changing the fourth digit results in 9666. 
	The maximum number is 9969.

	Constraints:
	
	1 <= num <= 10^4
	num's digits are 6 or 9.
	
	*/
    int maximum69Number (int num) {
		int numArray[5] = {0};
		int maximum =0;
		int a = 0;
		int l = 0;
		while (num > 0) {
			a = num % 10;
			num /= 10;
			numArray[l++] = a;
		}

		//cout << numArray[3] << numArray[2] << numArray[1] << numArray[0] << endl;

		for (int i = l; i > 0; i--)
		{
			if (numArray[i-1] == 6) {
				numArray[i-1] = 9;
				break;
			}
		}

		//cout << numArray[3] << numArray[2] << numArray[1] << numArray[0] << endl;

		//cout << "l:" << l << endl;

		for (int i = l; i > 0; i--) {
			maximum *= 10;
			maximum += numArray[i-1]; 
		}

		return maximum;
    }

	/*1186. Maximum Subarray Sum with One Deletion
	Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.
	
	Note that the subarray needs to be non-empty after deleting one element.
	
	Example 1:
	
	Input: arr = [1,-2,0,3]
	Output: 4
	Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
	Example 2:
	
	Input: arr = [1,-2,-2,3]
	Output: 3
	Explanation: We just choose [3] and it's the maximum sum.
	Example 3:
	
	Input: arr = [-1,-1,-1,-1]
	Output: -1
	Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
	 
	
	Constraints:
	
	1 <= arr.length <= 10^5
	-10^4 <= arr[i] <= 10^4
	*/
	int maximumSum_deprecated(vector<int>& array) {

		int arr[6] = {0};
		int minus_arr[6] = {0};	 
		int maximum_negative = -99999;

		int length = 0;
		int minus_count = 0;
		for (int i =0; i < array.size(); i++) {
			arr[i] = array[i];
			if (arr[i] < 0) {
				minus_arr[minus_count] = i;  // record the minus value index.
				minus_count++;

				if (maximum_negative < arr[i]) 
				{
					maximum_negative = arr[i];
				}
			}
			length++;
		}

		int best = 0; 
		for (int m = 0; m < minus_count; m++) {
			int sum = 0;

			int old = arr[minus_arr[m]];
			// change the negative array value to zero.
			arr[minus_arr[m]] = 0;

			// calculate the maximum subarray sum.
			for (int k =0; k < length; k++) {
				sum = max(arr[k], sum+arr[k]);
				best = max(best, sum);
			}

			arr[minus_arr[m]] = old;
		}
		if (best == 0) return maximum_negative;
		return best;
    }

	/*
	similar problem: 53. Maximum Subarray
		sum1: maximum sum subarray end with arr[i] without one deletion.
			the subarray only contains the element at position k.
			the subarray consists of a subarray that ends at position k-1, followed by the lement at position k.
		sum2: maximum sum subarray end with arr[i] with only one deletion.
			the subarray only delete the element at position k.
			the subarray consisits of a subarray that deletes once at position <= k-1, followed by the eleemnt at position k.

		for each index, the best solution is either from sum1 or sum2. we sweep from beginning to end.
		*/
	//vector<int> arrays4 = {2,1,-2,-5,-2};
	//vector<int> arrays3 = {-1,-1,-1,-1};
	int maximumSum(vector<int>& array) {

		int best1 = 0, best2=0, sum1 = 0, sum2 = 0;
		int max_negative = -9999;
		for (int k = 0; k < array.size(); k++) {
			if (array[k] && array[k] > max_negative)
				max_negative = array[k];
			sum2 = max(sum1, sum2+array[k]);
			sum1 = max(array[k], sum1+array[k]);
			best1 = max(best1,sum1);
			best2 = max(best2, sum2);
			// k=0, sum2:2, sum1:2
			// k=1, sum2:3, sum1:3
			// k=2, sum2:1, sum1:1
		}

		int result = max(best1, best2);
		if (result == 0) {
			return max_negative;
		}else return result;

	}

	/*
	 *Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
	 * */
	int maxSubArray(vector<int>& nums) {
		int best = 0, sum = 0;
		int max_negative = numeric_limits<int>::min();
		for (int k = 0; k < nums.size(); k++) {
			if (nums[k] <= 0 && nums[k] > max_negative)
				max_negative = nums[k];
			sum = max(nums[k], sum+nums[k]);
			best = max(best, sum);
		}
		if (best == 0) {
			return max_negative;
		} else return best; 
	}

/*
 *121. Best Time to Buy and Sell Stock
 Easy

 Say you have an array for which the ith element is the price of a given stock on day i.

 If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

 Note that you cannot sell a stock before you buy one.

 Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
			 Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 * */	

	/*
	sum1: maximum sum subarray end with arr[i] 
		the subarray only contains the element at position k.
		the subarray consists of a subarray that ends at position k-1, followed by the element at position k.
	*/
	int maxProfit(vector<int>& prices) {
			
	}

private:

};



void TestCase_1(Solution& sol){
	vector<int> arrays = {1,1, 0, 1, 1, 1};
	cout << "max subarray sum:" << sol.findMaxConsecutiveOnes(arrays) << endl;
}

void TestCase_2(Solution& sol){
	int num = 9969;
	num = 9996;
	cout << "max num:" << sol.maximum69Number(num) << endl;
}

void TestCase_3(Solution& sol){
	vector<int> arrays1 = {1,-2,0,3};
	vector<int> arrays2 = {1,-2,-2,3};
	vector<int> arrays3 = {-1,-1,-1,-1};
	vector<int> arrays4 = {2,1,-2,-5,-2};
	cout << "max sum num:" << sol.maximumSum(arrays1) << endl;
	cout << "max sum num:" << sol.maximumSum(arrays2) << endl;
	cout << "max sum num:" << sol.maximumSum(arrays3) << endl;
	cout << "max sum num:" << sol.maximumSum(arrays4) << endl;
}

void TestCase_4(Solution& sol){
	vector<int> arrays1 = {1,1, 0, 1, 1, 1};
	vector<int> arrays2 = {-1};
	vector<int> arrays3 = {0};
	vector<int> arrays4 = {-2147483647};
	cout << "max sum:" << sol.maxSubArray(arrays1) << endl;
	cout << "max sum:" << sol.maxSubArray(arrays2) << endl;
	cout << "max sum:" << sol.maxSubArray(arrays3) << endl;
	cout << "max sum:" << sol.maxSubArray(arrays4) << endl;
}

int main(){
	Solution sol;
	TestCase_1(sol);
	TestCase_2(sol);
	TestCase_3(sol);
	TestCase_4(sol);

    return 0;
}
