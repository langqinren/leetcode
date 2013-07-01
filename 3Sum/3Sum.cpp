/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
 */

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		int n = num.size();
		sort(num.begin(), num.end());
		set < vector<int> > rel;
		for (int k=0; k<n-2; k++) {
			int target = 0 - num[k];
			int i = k+1;
			int j = n-1;

			while (i < j) {
				int sum = num[i] + num[j];
				if (sum < target) {
					i++;
				} else if (sum > target) {
					j--;
				} else {
					vector<int> triple;
					triple.push_back(num[k]);
					triple.push_back(num[i]);
					triple.push_back(num[j]);
					rel.insert(triple);
					i++, j--;
				}
			}
		}
        
		vector < vector<int> > out(rel.begin(), rel.end());
		return out;
    }
};

int main(void) {
	int A[] = {-1,0,1};
	vector<int> V(A, A+3);

	Solution s;
	vector < vector<int> > out = s.threeSum(V);
	return 1;
}