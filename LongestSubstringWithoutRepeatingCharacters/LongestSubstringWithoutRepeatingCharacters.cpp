/*
 Given a string, find the length of the longest substring without repeating characters. 
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int i = 0, j = 0, l = s.length();
		int ml = 0, cl = 0;

		int  charMap[256] = {0};
		char dupChar, curChar;
		bool dupFlag = false;
		while (j <= l) {
			if (!dupFlag) {
				cl = j-i;
				ml = ml > cl ? ml : cl;

				curChar = s[j];
				charMap[curChar]++;
				if (charMap[curChar] >= 2) {
					dupFlag = true;
					dupChar = curChar;
				} 
				j++;
			} else {
				curChar = s[i];
				charMap[curChar]--;

				if (curChar == dupChar) dupFlag = false;
				i++;
			} 
		}

		return ml;
    }
};