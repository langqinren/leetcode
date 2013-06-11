/*
Given a string S, find the longest palindromic substring in S. You may assume that 
the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */
#include <string>

using namespace std;

class Solution {
public:
	int findPalindrome(string str, int s, int l, bool even) {
		int i, j, d = 0;
		if (even) i = s-1, j = s;
		else      i = s-1, j = s+1;

		while (i >= 0 && j < l && str[i--] == str[j++]) d++;
		return d; 
	}

    string longestPalindrome(string s) {
		int ml = 0, cl = 0, l = s.length();
		int hl = 0;
		string pStr;

		for (int i=0; i<l; i++) {
			hl = findPalindrome(s, i, l, true);
			cl = 2*hl;
			if (cl > ml) {
				ml   = cl;
				pStr = s.substr(i-hl, cl); 
			}

			hl = findPalindrome(s, i, l, false);
			cl = 2*hl+1;
			if (cl > ml) {
				ml   = cl;
				pStr = s.substr(i-hl, cl); 
			}
		}

		return pStr;
    }
};
