/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid 
but "(]" and "([)]" are not.
 */
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isMatch(char s, char c) {
		switch (s) {
		case '(': return c == ')';
		case '[': return c == ']';
		case '{': return c == '}';
		default:  return false;
		}
	}

    bool isValid(string s) {
		int  l = (int)s.length();
		char c;

		stack<char> S;
		for (int i=0; i<l; i++) {
			c = s[i];
			if (c == '(' || c == '[' || c == '{') 
				S.push(c);
			else if (c == ')' || c == ']' || c == '}') {
				if (!S.empty() && isMatch(S.top(), c)) 
					S.pop();
				else 
					return false;
			}
		}

		return S.empty();
    }
};
