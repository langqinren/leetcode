/*
Given an array S of n integers, find three integers in S such that the sum is closest 
to a given number, target. Return the sum of the three integers. You may assume that 
each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	// NOTE: when you need initialize a value for comparisons, there are two ways of
	// initalization. 
	// (1) take the first values from the input 
	// (2) use INT_MAX, INT_MIN that can never be the output.
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
	
		int close = num[0] + num[1] + num[2];
		int n     = num.size();
		for (int k=0; k<n-2; k++) {
			int i = k+1;
			int j = n-1;
			while (i < j) {
				int sum = num[k] + num[i] + num[j];

				if (sum < target) {
					if (abs(close - target) > abs(sum - target)) close = sum;
					i++;
				} else if (sum > target) {
					if (abs(close - target) > abs(sum - target)) close = sum;
					j--;
				} else {
					return target;
				}
			}
		}

		return close;
    }
};
