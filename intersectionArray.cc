#include <set>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> intersectionSet;
		set<int>::iterator it ;
		set<int>::iterator it2;
		set<int> resultSet;
		vector<int> intersectVector;

		if (nums1.size() > nums2.size()) 
		{
			for (int i = 0; i < nums2.size(); i++) {
				it = intersectionSet.find(nums2[i]);
				if (it == intersectionSet.end())
					intersectionSet.insert(nums2[i]);
			}
			for (int i = 0; i < nums1.size(); i++) {
				it = intersectionSet.find(nums1[i]);
				it2 = resultSet.find(nums1[i]);

				if (it != intersectionSet.end() && it2 == resultSet.end())
					resultSet.insert(*it);
			}

		} else {
			for (int i = 0; i < nums1.size(); i++) {
				it = intersectionSet.find(nums1[i]);
				if (it == intersectionSet.end())
					intersectionSet.insert(nums1[i]);
			}
			for (int i = 0; i < nums2.size(); i++) {
				it = intersectionSet.find(nums2[i]);
				it2 = resultSet.find(nums2[i]);

				if (it != intersectionSet.end() && it2 == resultSet.end())
					resultSet.insert(*it);
			}
		}

		it = resultSet.begin();
		while(it != resultSet.end()) {
			intersectVector.push_back(*it);
			it++;
		}

		return intersectVector;
    }
};

int main(){
	Solution sol;
	vector<int> nums1{1,2,2,1};
	vector<int> nums2{2, 2};
	vector<int> result;

	result = sol.intersection(nums1, nums2);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]<< ",";
	}

	cout << endl;

	return 0;

}
