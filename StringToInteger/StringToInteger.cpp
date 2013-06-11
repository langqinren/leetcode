/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please
do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input 
specs). You are responsible to gather all the input requirements up front.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
		if (!str) return 0;

		long long val = 0;
		bool      pos = true;

		while (*str == ' ') str++;
		if (*str == '+') pos = true, str++;
		if (*str == '-') pos = false, str++;

		while ('0' <= *str && *str <= '9') {
			val *= 10;
			val += *str - '0';
			str++;
		}

		if (pos) return val  > INT_MAX ? INT_MAX : val;
		else     return -val < INT_MIN ? INT_MIN : -val; 
    }
};