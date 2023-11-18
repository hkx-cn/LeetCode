#include "LeetCodeMain.h"
#include "LeetCode21.h"

int main()
{
	Solution solution;
	ListNode *a = new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = new ListNode(4);
	ListNode *b = new ListNode(1);
	b->next = new ListNode(3);
	b->next->next = new ListNode(4);
	ListNode *result = solution.mergeTwoLists(a, b);
	cin.get();
}