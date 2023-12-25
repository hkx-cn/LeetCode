// 445. 两数相加 II
// 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
// 示例1：
// 输入：l1 = [7,2,4,3], l2 = [5,6,4]
// 输出：[7,8,0,7]
// 示例2：
// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[8,0,7]
// 示例3：
// 输入：l1 = [0], l2 = [0]
// 输出：[0]

// 提示：
// 链表的长度范围为 [1, 100]
// 0 <= node.val <= 9
// 输入数据保证链表代表的数字无前导 0

// 进阶：如果输入链表不能翻转该如何解决？
#include "LeetCode445.hpp"
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
ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result1 = nullptr, *result2 = nullptr, *temp = nullptr;
    int sum = 0, carry = 0;
    while (l1 != nullptr)
    {
        temp = new ListNode(l1->val);
        temp->next = result1;
        result1 = temp;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        temp = new ListNode(l2->val);
        temp->next = result2;
        result2 = temp;
        l2 = l2->next;
    }
    ListNode *result = new ListNode();
    while (true)
    {
        sum = carry;
        if (result1 != nullptr)
        {
            sum += result1->val;
            result1 = result1->next;
        }
        if (result2 != nullptr)
        {
            sum += result2->val;
            result2 = result2->next;
        }
        ListNode *temp = new ListNode(sum % 10);
        carry = sum / 10;
        temp->next = result->next;
        result->next = temp;
        if (!(result1 != nullptr || result2 != nullptr || carry != 0))
            break;
    }
    return result->next;
};
// 方法一：栈
// 思路与算法 
// 本题的主要难点在于链表中数位的顺序与我们做加法的顺序是相反的，为了逆序处理所有数位，我们可以使用栈：把所有数字压入栈中，再依次取出相加。计算过程中需要注意进位的情况。
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         stack<int> s1, s2;
//         while (l1) {
//             s1.push(l1 -> val);
//             l1 = l1 -> next;
//         }
//         while (l2) {
//             s2.push(l2 -> val);
//             l2 = l2 -> next;
//         }
//         int carry = 0;
//         ListNode* ans = nullptr;
//         while (!s1.empty() or !s2.empty() or carry != 0) {
//             int a = s1.empty() ? 0 : s1.top();
//             int b = s2.empty() ? 0 : s2.top();
//             if (!s1.empty()) s1.pop();
//             if (!s2.empty()) s2.pop();
//             int cur = a + b + carry;
//             carry = cur / 10;
//             cur %= 10;
//             auto curnode = new ListNode(cur);
//             curnode -> next = ans;
//             ans = curnode;
//         }
//         return ans;
//     }
// };
// 复杂度分析
// 时间复杂度：O(max⁡(m,n))，其中 m 和 n 分别为两个链表的长度。我们需要遍历两个链表的全部位置，而处理每个位置只需要 O(1) 的时间。
// 空间复杂度：O(m+n)，其中 m 和 n 分别为两个链表的长度。空间复杂度主要取决于我们把链表内容放入栈中所用的空间。