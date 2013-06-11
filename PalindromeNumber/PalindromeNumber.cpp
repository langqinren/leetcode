/*
 Determine whether an integer is a palindrome. Do this without extra space.
 */

class Solution {
public:
    bool isPalindrome1(int x) {
		if (x < 0) return false;
		
		long long lx = x;
		long long rx = 0;

		while (x) {
			rx *= 10;
			rx += x % 10;
			x  /= 10;
		}

		return lx == rx;
    }

	// better solution: break in the middle
	bool isPalindromeHelper(int lx, int& rx) {
		if (lx <= 0) return true;

		if (!isPalindromeHelper(lx / 10, rx)) return false;
		bool t = (lx % 10) == (rx % 10);
		rx /= 10;
		return t;
	}

	bool isPalindrome(int x) {
		if (x < 0) return false;
		return isPalindromeHelper(x, x);
	}
};
