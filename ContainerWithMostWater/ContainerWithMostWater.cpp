/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at 
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of 
line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms 
a container, such that the container contains the most water.

Note: You may not slant the container.
 */
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
		int n = height.size();
		if (n <= 1) return 0;

		int i=0, j=n-1;
		int cArea=0, mArea=0;
		
		while (i < j) {
			cArea = (j-i)*min(height[i], height[j]);
			mArea = mArea > cArea ? mArea : cArea;
			height[i] > height[j] ? j-- : i++;
		}
		
		return mArea;
    }
};