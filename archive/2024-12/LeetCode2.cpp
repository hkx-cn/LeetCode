// 2. 两数相加
// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序
// 的方式存储的，并且每个节点只能存储 一位 数字。
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 示例 1：
// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.
// 示例 2：
// 输入：l1 = [0], l2 = [0]
// 输出：[0]
// 示例 3：
// 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// 输出：[8,9,9,9,0,0,0,1]

// 提示：
// 每个链表中的节点数在范围 [1, 100] 内
// 0 <= Node.val <= 9
// 题目数据保证列表表示的数字不含前导零
#include "LeetCode2.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result, *next;
    int carry = 0;
    result = (struct ListNode*)malloc(sizeof(struct ListNode));
    next = result;
    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            next->next->val = (l2->val + carry) % 10;
            next = next->next;
            next->next = NULL;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        } else if (l2 == NULL) {
            next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            next->next->val = (l1->val + carry) % 10;
            next = next->next;
            next->next = NULL;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        } else {
            next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            next->next->val = (l1->val + l2->val + carry) % 10;
            next = next->next;
            next->next = NULL;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    if (carry > 0) {
        next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        next->next->val = carry;
        next->next->next = NULL;
    }
    return result->next;
}

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

// ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
//     ListNode *result = new ListNode(), *next = result;
//     bool carry = false;
//     int val = 0;
//     while (l1 != nullptr && l2 != nullptr) {
//         if (l1 == nullptr) {
//             val = carry ? l2->val + 1 : l2->val;
//             carry = val >= 10 ? true : false;
//             l2 = l2->next;
//         } else if (l2 == nullptr) {
//             val = carry ? l1->val + 1 : l1->val;
//             carry = val >= 10 ? true : false;
//             l1 = l1->next;
//         } else {
//             val = carry ? l1->val + l2->val + 1 : l1->val + l2->val;
//             carry = val >= 10 ? true : false;
//             l1 = l1->next;
//             l2 = l2->next;
//         }
//         val = val % 10;
//         next->next = new ListNode(val);
//         next = next->next;
//     }
//     if (carry) {
//         next->next = new ListNode(1);
//     }
//     return result->next;
// };

// ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
// {
//     ListNode *result = new ListNode, *next = result;
//     int sum = -1;
//     bool add = false;
//     while (l1 != nullptr || l2 != nullptr)
//     {
//         if (add)
//             sum = 1;
//         else
//             sum = 0;

//         if (l1 != nullptr)
//         {
//             sum += l1->val;
//             l1 = l1->next;
//         }
//         if (l2 != nullptr)
//         {
//             sum += l2->val;
//             l2 = l2->next;
//         }
//         if (sum > 9)
//         {
//             add = true;
//             sum -= 10;
//         }
//         else
//         {
//             add = false;
//         }
//         next->next = new ListNode(sum);
//         next = next->next;
//     }
//     if (add)
//         next->next = new ListNode(1);

//     return result->next;
// };
// 方法一：模拟
// 思路与算法
// 由于输入的两个链表都是逆序存储数字的位数的，因此两个链表中同一位置的数字可以直接相加。
// 我们同时遍历两个链表，逐位计算它们的和，并与当前位置的进位值相加。具体而言，如果当前两个链表处相应位置的数字为
// n1,n2，进位值为 carry，则它们的和为
// n1+n2+carry；其中，答案链表处相应位置的数字为
// (n1+n2+carry) mod 10，而新的进位值为 ⌊(n1+n2+carry)/10⌋。
// 如果两个链表的长度不同，则可以认为长度短的链表的后面有若干个 000 。
// 此外，如果链表遍历结束后，有
// carry>0，还需要在答案链表的后面附加一个节点，节点的值为 carry。
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode *head = nullptr, *tail = nullptr;
//         int carry = 0;
//         while (l1 || l2) {
//             int n1 = l1 ? l1->val : 0;
//             int n2 = l2 ? l2->val : 0;
//             int sum = n1 + n2 + carry;
//             if (!head) {
//                 head = tail = new ListNode(sum % 10);
//             } else {
//                 tail->next = new ListNode(sum % 10);
//                 tail = tail->next;
//             }
//             carry = sum / 10;
//             if (l1) {
//                 l1 = l1->next;
//             }
//             if (l2) {
//                 l2 = l2->next;
//             }
//         }
//         if (carry > 0) {
//             tail->next = new ListNode(carry);
//         }
//         return head;
//     }
// };
// 复杂度分析
// 时间复杂度：O(max(m,n))，其中 m 和 n
// 分别为两个链表的长度。我们要遍历两个链表的全部位置，而处理每个位置只需要 O(1)
// 的时间。 空间复杂度：O(1)。注意返回值不计入空间复杂度。
