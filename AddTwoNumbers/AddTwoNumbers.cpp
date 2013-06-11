/*
You are given two linked lists representing two non-negative numbers. The digits are 
stored in reverse order and each of their nodes contain a single digit. Add the two 
numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
 */
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *head = NULL, *l3;
		
		int carry = 0;
		int v1, v2, sum;
		while (l1 || l2) {
			v1    = l1 ? l1->val : 0;
			v2    = l2 ? l2->val : 0;
			sum   = v1 + v2 + carry; 
			carry = sum / 10;
			sum   = sum % 10;

			if (!head) head     = new ListNode(sum), l3 = head;
			else       l3->next = new ListNode(sum), l3 = l3->next;

			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}

		if (carry) l3->next = new ListNode(1);

		return head;
    }
};