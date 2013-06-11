/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

#include <vector>
#include <stack>
#include <queue>

using namespace std;

 struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef pair<pair<int, int>, TreeNode**> StackNode;

class Solution {
public:
	// method 1: iterative solution 1 (using a stack)
    TreeNode *sortedArrayToBST(vector<int> &num) {	
		TreeNode *root = NULL, **parent = NULL, *current = NULL;
		if (num.size() <= 0) return root;

		int L, R, M;
		L = 0, R = num.size()-1; 
		
		stack<StackNode> nodeStack;
		StackNode node; 
		node.first.first = L, node.first.second = R, node.second = NULL;
		nodeStack.push(node);

		while (!nodeStack.empty()) {
			node    = nodeStack.top(), nodeStack.pop();
			L       = node.first.first;
			R       = node.first.second;
			M       = L + (R-L)/2;
			parent  = node.second;
			current = new TreeNode(num[M]);
			parent ? *parent = current : root = current;

			
			if (R >= M+1) {
				node.first.first = M+1, node.first.second = R, node.second = &current->right;
				nodeStack.push(node);
			}

			if (L <= M-1) {
				node.first.first = L, node.first.second = M-1, node.second = &current->left;
				nodeStack.push(node);	
			} 
		}

		return root;
    }


	//  method 2: iterative solution 1 (using a queue)
	TreeNode *sortedArrayToBST1(vector<int> &num) {
		if (num.size() <= 0) return NULL;

		int L=0, R=num.size()-1, M=0;
		TreeNode *root, **parent, *current;
		
		StackNode node; 
		node.first.first = L, node.first.second = R, node.second = NULL;
		queue<StackNode> nodeQ; nodeQ.push(node);

		while (!nodeQ.empty()) {
			node = nodeQ.front(); nodeQ.pop();

			L = node.first.first;
			R = node.first.second;
			M = L + (R-L)/2;
			current = new TreeNode(num[M]); 
			parent  = node.second;
			parent  ? *parent = current : root = current;
			
			if (L <= M-1) {
				node.first.first = L, node.first.second = M-1, node.second = &current->left;
				nodeQ.push(node);
			}

			if (R >= M+1) {
				node.first.first = M+1, node.first.second = R, node.second = &current->right;
				nodeQ.push(node);
			}
		}

		return root;
	}
};

/*
int main(void) {
	int A[] = {5, 9, 21, 24};
	int n   = sizeof(A)/sizeof(int);
	vector<int> V(A, A+n);

	Solution s;
	TreeNode* root = s.sortedArrayToBST1(V);
}
*/