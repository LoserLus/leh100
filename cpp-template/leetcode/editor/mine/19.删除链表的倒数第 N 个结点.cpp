/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30202
 *
 * [19] 删除链表的倒数第 N 个结点
 */

#include <iostream>
#include <vector>
#include <string>
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = dummy.next;
        ListNode* second = &dummy;
        while(n--)
        {
            first = first->next;
        }
        while(first)
        {
            first=first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy.next;
    }
	// ListNode *removeNthFromEnd(ListNode *head, int n)
	// {
	// 	if (head == nullptr) return head;
	// 	int len = 0;
	// 	ListNode dummy(0);
	// 	dummy.next = head;
	// 	ListNode *node = &dummy;
	// 	while (node)
	// 		{
	// 			len++;
	// 			node = node->next;
	// 		}
	// 	node = &dummy;
	// 	int cnt = 0;
	// 	for (int i = 0; i < len - n -1; ++i)
	// 		{
	// 			node = node->next;
	// 		}
	// 	node->next = node->next->next;
	// 	return dummy.next;
	// }
};
// @lc code=end

int main()
{
	Solution solution;
	// your test code here
	ListNode *head = ListNode::createHead({1,2,3,4,5});
	int n = 2;
	ListNode *res = solution.removeNthFromEnd(head, n);
	ListNode::print(res);
	ListNode::freeList(res);
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
