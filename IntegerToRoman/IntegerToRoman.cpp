/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
 */

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/*
	 * I = 1
	 * V = 5
	 * X = 10
	 * L = 50
	 * C = 100
	 * D = 500
	 * M = 1000
	 */
	static unordered_map<int, char> createMap() {
		unordered_map<int, char> m;
		m[1]     = 'I';
		m[5]     = 'V';
		m[10]    = 'X';
		m[50]    = 'L';
		m[100]   = 'C';
		m[500]   = 'D';
		m[1000]  = 'M';
		m[5000]  = ' ';
		m[10000] = ' ';
		return m;
	}

    string intToRoman(int num) {
		if (num <= 0 || num > 3999) return "";

		static unordered_map<int, char> romanMap = createMap();		        
    
		string roman = "";
		int    mul   = 1000;
		int    val   = 0;
		char   c1, c5, c10;
		while (mul) {
			val = num / mul;
			if (val > 0) {
				c1  = romanMap[mul];
				c5  = romanMap[5*mul];
				c10 = romanMap[10*mul];
				
				switch (val) {
				case 1:
				case 2:
				case 3:
					roman.append(val, c1);
					break;

				case 4:
					roman.append(1, c1);
					roman.append(1, c5);
					break;
				case 5:
				case 6:
				case 7:
				case 8:
					roman.append(1, c5);
					roman.append(val-5, c1);
					break;
				case 9:
					roman.append(1, c1);
					roman.append(1, c10);
					break;
				}

				num -= val * mul;
			}

			mul /= 10;
		}

		return roman;
	}
};