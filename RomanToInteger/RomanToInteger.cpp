/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
 */
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	
	static unordered_map<char, int> createMap() {
		unordered_map<char, int> m;
		m['\0'] = 0;
		m['I']  = 1;
		m['V']  = 5;
		m['X']  = 10;
		m['L']  = 50;
		m['C']  = 100;
		m['D']  = 500;
		m['M']  = 1000;
		return m;
	}

    int romanToInt(string s) {
		int l = s.length();
		if (l <= 0) return 0;
		
		static unordered_map<char, int> romanMap = createMap();
		int c, n, v = 0;
		for (int i=0; i<l; i++) {
			c = romanMap[s[i]]; 
			n = romanMap[s[i+1]];
			
			if (c >= n) v += c;
			else        v -= c;
		}
		return v;
    }
};