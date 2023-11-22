#include "LeetCodeMain.h"
#include "LeetCode2.h"

int main()
{
	Solution solution;
	ListNode *a = new ListNode(2);
	a->next = new ListNode(4);
	a->next->next = new ListNode(3);
	ListNode *b = new ListNode(5);
	b->next = new ListNode(6);
	b->next->next = new ListNode(4);
	ListNode *result = solution.addTwoNumbers(a, b);
	cin.get();
}