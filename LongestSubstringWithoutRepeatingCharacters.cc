#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s){
			int n = s.length();
			unordered_set<char> charSet ;
			int ans = 0; 
			int i = 0;
			int j = 0;
			while (i < n && j < n) {
				if (charSet.find(s[j]) == charSet.end())
				{
					charSet.insert(s[j++]);
					ans = max(ans, j-i)
				} else {
					charSet.erase(s[i++]);
				}
			}

			return ans;
		}
};

int main(){
	Solution sol;
	string str = "abcabcbb";

	
}
