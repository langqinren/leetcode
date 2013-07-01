/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	static const string digCharMap[10];

	// solution 1: recursive solution
    void letterCombinationsHelper(string& digits, int l, string s, vector<string>& out) { 
		if (l >= (int)digits.length()) {
			out.push_back(s);
			return;
		}

		int    d = digits[l]-'0';
		string c = digCharMap[d];
		for (int i=0; i<(int)c.length(); i++) {
			letterCombinationsHelper(digits, l+1, s + c[i], out);
		}
	}

	vector<string> letterCombinations1(string digits) {    
		vector<string> out;
		letterCombinationsHelper(digits, 0, "", out);
		return out;
	}
	

	// solution 2: iterative solution
	// method 2.1: Using two stacks to simulate the recusive calls.  
	//             Two queues, stacks, vectors should work for iterative solution
	vector<string> letterCombinations2(string digits) {
		vector<string>  pre, cur; 
		vector<string> *pPre = &pre, *pCur=&cur;

		pPre->push_back("");
		for (int i=0; i<(int)digits.length(); i++) {
			pCur->clear();

			int    d = digits[i]-'0';
			string c = digCharMap[d];
			for (int j=0; j<(int)pPre->size(); j++) {
				for (int k=0; k<(int)c.length(); k++) {
					pCur->push_back((*pPre)[j] + c[k]);
				}
			}

			swap(pPre, pCur);
		}

		return *pPre;
	}


	// method 2.2: use vector expanding to simulate the branching process
	//             of recursive calls.
	vector<string> letterCombinations3(string digits) {
		vector<string> out(1, "");
	
		int d, l; string s;
		for (int i=0; i<(int)digits.length(); i++) {
			d = digits[i]-'0';
			s = digCharMap[d];
			l = out.size();

			for (int j=0; j<s.length(); j++) {
				if (j == 0) {
					for (int k=0; k<l; k++) out[k] += s[0];
				} else {
					for (int k=0; k<l; k++) {
						string str = out[k];
						str[i] = s[j];
						out.push_back(str);
					}
				}
			}
		}

		return out;
	}

	// method 2.3:  (from PIE)
	vector<string> letterCombinations() {

	}
};

const string Solution::digCharMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 