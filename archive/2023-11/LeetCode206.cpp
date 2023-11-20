// 206. 反转链表
// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
// 示例 1：
// 输入：head = [1,2,3,4,5]
// 输出：[5,4,3,2,1]
// 示例 2：
// 输入：head = [1,2]
// 输出：[2,1]
// 示例 3：

// 输入：head = []
// 输出：[]
// 提示：

// 链表中节点的数目范围是 [0, 5000]
// -5000 <= Node.val <= 5000

// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

#include "LeetCode206.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode *Solution::reverseList(ListNode *head)
{
	ListNode *result;
	if (head == nullptr)
	{
		return head;
	}
	if (head->next == nullptr)
	{
		return head;
	}
	else
	{
		result = Solution::reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return result;
	}
};
// 方法一：迭代
// 假设链表为 1→2→3→∅1 \rightarrow 2 \rightarrow 3 \rightarrow \varnothing1→2→3→∅，我们想要把它改成 ∅←1←2←3\varnothing \leftarrow 1 \leftarrow 2 \leftarrow 3∅←1←2←3。

// 在遍历链表时，将当前节点的 next\textit{next}next 指针改为指向前一个节点。由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。在更改引用之前，还需要存储后一个节点。最后返回新的头引用。
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
//         while (curr) {
//             ListNode* next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }
// };
// 复杂度分析

// 时间复杂度：O(n)O(n)O(n)，其中 nnn 是链表的长度。需要遍历链表一次。

// 空间复杂度：O(1)O(1)O(1)。

// 方法二：递归
// 递归版本稍微复杂一些，其关键在于反向工作。假设链表的其余部分已经被反转，现在应该如何反转它前面的部分？

// 假设链表为： n1→…→nk−1→nk→nk+1→…→nm→∅n_1\rightarrow \ldots \rightarrow n_{k-1} \rightarrow n_k \rightarrow n_{k+1} \rightarrow \ldots \rightarrow n_m \rightarrow \varnothingn 
// 1
// ​
//  →…→n 
// k−1
// ​
//  →n 
// k
// ​
//  →n 
// k+1
// ​
//  →…→n 
// m
// ​
//  →∅

// 若从节点 nk+1n_{k+1}n 
// k+1
// ​
//   到 nmn_mn 
// m
// ​
//   已经被反转，而我们正处于 nkn_kn 
// k
// ​
//  。

// n1→…→nk−1→nk→nk+1←…←nmn_1\rightarrow \ldots \rightarrow n_{k-1} \rightarrow n_k \rightarrow n_{k+1} \leftarrow \ldots \leftarrow n_mn 
// 1
// ​
//  →…→n 
// k−1
// ​
//  →n 
// k
// ​
//  →n 
// k+1
// ​
//  ←…←n 
// m
// ​
 

// 我们希望 nk+1n_{k+1}n 
// k+1
// ​
//   的下一个节点指向 nkn_kn 
// k
// ​
//  。

// 所以，nk.next.next=nkn_k.\textit{next}.\textit{next} = n_kn 
// k
// ​
//  .next.next=n 
// k
// ​
//  。

// 需要注意的是 n1n_1n 
// 1
// ​
//   的下一个节点必须指向 ∅\varnothing∅。如果忽略了这一点，链表中可能会产生环。
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (!head || !head->next) {
//             return head;
//         }
//         ListNode* newHead = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return newHead;
//     }
// };
// 复杂度分析

// 时间复杂度：O(n)O(n)O(n)，其中 nnn 是链表的长度。需要对链表的每个节点进行反转操作。

// 空间复杂度：O(n)O(n)O(n)，其中 nnn 是链表的长度。空间复杂度主要取决于递归调用的栈空间，最多为 nnn 层。