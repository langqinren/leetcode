/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
		bool pos = x >= 0; x = pos ? x : -x; 
		long long rx = 0;

		while (x) {
			rx *= 10;
			rx += x % 10;
			x  /= 10;
		}

		rx = pos ? rx : -rx;
		if (pos) return rx > INT_MAX ? INT_MAX : rx;
		else     return rx < INT_MIN ? INT_MIN : rx;
	}
};