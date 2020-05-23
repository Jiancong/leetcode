#include <set>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> intersectionSet;
		set<int>::iterator it ;
		vector<int> intersectVector;

		if (nums1.size() > nums2.size()) 
		{
			for (int i = 0; i < nums2.size(); i++) {
				it = intersectionSet.find(nums2[i]);
				if (it == intersectionSet.end())
					intersectionSet.insert(nums2[i]);
			}

			cout << "intersectSet size:" << intersectionSet.size() << endl;

			for (int i = 0; i < nums1.size(); i++) {
				it  = intersectionSet.find(nums1[i]);
				if (it != intersectionSet.end())
					intersectVector.push_back(*it);
			}

			cout << "intersectVector size:" << intersectVector.size() << endl;

		} else {
			for (int i = 0; i < nums1.size(); i++) {
				it = intersectionSet.find(nums1[i]);
				if (it == intersectionSet.end())
					intersectionSet.insert(nums1[i]);
			}

			cout << "intersectSet size:" << intersectionSet.size() << endl;

			for (int i = 0; i < nums2.size(); i++) {
				it  = intersectionSet.find(nums2[i]);
				if (it != intersectionSet.end())
					intersectVector.push_back(*it);
			}
			cout << "intersectVector size:" << intersectVector.size() << endl;

		}

		return intersectVector;
    }
};

int main(){
	Solution sol;
	vector<int> nums1{1,2,2,1};
	vector<int> nums2{2, 2};
	vector<int> result;

	for (int i = 0; i < nums1.size(); i++)
		cout << nums1[i] << endl;
	result = sol.intersection(nums1, nums2);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]<< ",";
	}

	cout << endl;

}
