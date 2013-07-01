/*
Given an array S of n integers, are there elements a, b, c, and d in S such that 
a + b + c + d = target? Find all unique quadruplets in the array which gives the 
sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
	(ie, a ? b ? c ? d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
 */
#include <vector>
#include <algorithm>

using namespace std;

typedef pair< int, pair<int, int> > Elem2;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<Elem2> sum2;
		
		int N = (int)num.size();
		for (int i=0; i<N-1; i++) {
			for (int j=i+1; j<N; j++) {
				Elem2 elem;
				elem.first = num[i]+num[j];
				elem.second.first  = num[i];
				elem.second.second = num[j];
				sum2.push_back(elem);
			}
		}

		sort(sum2.begin(), sum2.end());
		int i=0, j=sum2.size()-1;
		while (i<j) {
			
		}
    }
};
