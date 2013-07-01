/*
Write a function to find the longest common prefix string amongst an array of strings.
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		int n = strs.size();
		if (n <= 0) return "";

		string base = strs[0];
		int l = 0; bool com = true;
		for (; l<base.length(); l++) {
			for (int i=0; i<n; i++) {
				if (base[l] != strs[i][l]) {
					com = false; break;
				}
			}
			if (!com) break;
		}

		return base.substr(0, l);
    }
};
