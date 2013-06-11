/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of 
rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 0)  return "";
		if (nRows == 1) return s;

		vector<string> strRows(nRows, "");

		bool zig = false;
		int  cnt = 0;
		for (int i=0; i<(int)s.length(); i++) {
			if (!zig || nRows == 2) {
				strRows[cnt] += s[i];
				if (++cnt >= nRows) zig = true, cnt = 0;
			} else {
				strRows[nRows-2-cnt] += s[i];
				if (++cnt >= nRows-2) zig = false, cnt = 0;
			}
		}

		string out = "";
		for (int i=0; i<(int)strRows.size(); i++) {
			out += strRows[i];
		}
		return out;
    }
};