/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	vector< pair<int, int> > nums;
	vector<int> idxs;
	for (int i=0; i<numbers.size(); i++) nums.push_back(pair<int, int>(numbers[i], i+1));
        sort(nums.begin(), nums.end());

	int i=0, j=nums.size()-1, sum=0;
	while (i<j)
	{
		sum = nums[i].first+nums[j].first;
		if (sum < target)
			i++;
		else if (sum > target)
			j--;
		else
		{
			int p1 = nums[i].second, p2 = nums[j].second;
			if (p1 > p2) swap(p1, p2);
			idxs.push_back(p1);
			idxs.push_back(p2);
			return idxs;
		}
	}

	return idxs;
    }
};

void print(vector<int>& V)
{
	for (int i=0; i<V.size(); i++)
		cout<<V[i]<<" ";
	cout<<endl;
}
