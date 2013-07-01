/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (n <= 0 || !head) return head;

		ListNode *slow = NULL;
		ListNode *fast = head;
		ListNode *del  = NULL;
		
		int c = 0;
		while (fast && ++c < n) fast = fast->next;
	
		if (!fast) return head;
			
		while (fast->next) {
			fast = fast->next;
			slow = slow ? slow->next : head;
 		}	


		if (slow) del = slow->next, slow->next = del->next;
		else      del = head, head = head->next;
		delete del;
		return head;
	}
};