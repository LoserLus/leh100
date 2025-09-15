/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30202
 *
 * [2] 两数相加
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode *l1_p = l1;
		ListNode *l2_p = l2;
		ListNode dummy(0);
		ListNode *node = &dummy;
		int sum = 0;
		int carry = 0;
		while (l1_p || l2_p)
			{
                // 使用三目运算符判断，若为空指针即为0
                int a = l1_p?l1_p->val:0;
                int b = l2_p?l2_p->val:0;
				sum = a + b + carry;
				ListNode *tmp = new ListNode(sum % 10);
				carry = sum / 10;
				node->next = tmp;
				node = node->next;
                // 迭代的时候判断是否指向下一个
                l1_p = l1_p?l1_p->next:l1_p;
                l2_p = l2_p?l2_p->next:l2_p;
			}
		if (carry > 0)
			{
				ListNode *tmp = new ListNode(carry);
				node->next = tmp;
				node = node->next;
			}
		return dummy.next;
	}
	// ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	// {
	// 	if (l1 == nullptr) return l2;
	// 	if (l2 == nullptr) return l1;

	// 	ListNode *l1_p = l1;
	// 	ListNode *l2_p = l2;
	// 	ListNode dummy(0);
	// 	ListNode *node = &dummy;
	// 	int sum = 0;
	// 	int carry = 0;
	// 	while (l1_p && l2_p)
	// 		{
	// 			sum = l1_p->val + l2_p->val + carry;
	// 			ListNode *tmp = new ListNode(sum % 10);
	// 			carry = sum / 10;
	// 			node->next = tmp;
	// 			node = node->next;
    //             l1_p = l1_p->next;
    //             l2_p = l2_p->next;
	// 		}
	// 	while (l1_p || l2_p)
	// 		{
	// 			if (l1_p)
	// 				{
	// 					sum = l1_p->val + carry;
    //                     l1_p = l1_p->next;
	// 				}
	// 			else
	// 				{
	// 					sum = l2_p->val + carry;
    //                     l2_p = l2_p->next;
	// 				}
	// 			ListNode *tmp = new ListNode(sum % 10);
	// 			carry = sum / 10;
	// 			node->next = tmp;
	// 			node = node->next;
	// 		}
	// 	if (carry == 1)
	// 		{
	// 			ListNode *tmp = new ListNode(1);
	// 			node->next = tmp;
	// 			node = node->next;
	// 		}
	// 	return dummy.next;
	// }
};
	// @lc code=end

	int main()
	{
		Solution solution;
		// your test code here
		ListNode *l1 = ListNode::createHead({9,9,9,9,9,9,9});
		ListNode *l2 = ListNode::createHead({9,9,9});
		ListNode *res = solution.addTwoNumbers(l1, l2);
		ListNode::print(res);
		ListNode::freeList(l1);
		ListNode::freeList(l2);
		ListNode::freeList(res);
	}

	/*
	// @lcpr case=start
	// [2,4,3]\n[5,6,4]\n
	// @lcpr case=end

	// @lcpr case=start
	// [0]\n[0]\n
	// @lcpr case=end

	// @lcpr case=start
	// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
	// @lcpr case=end

	 */
