/*
 * @lc app=leetcode.cn id=206 lang=cpp
 * @lcpr version=30202
 *
 * [206] 反转链表
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* node = nullptr;
        ListNode* next_node = nullptr;
        ListNode* pre_node = nullptr;
        node = head;
        while(node!=nullptr)
        {
            next_node = node->next;
            node->next = pre_node;
            pre_node = node;
            node = next_node;
        }
        return pre_node;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    ListNode* head = ListNode::createHead({1,2,3,4,5});
    ListNode* res = solution.reverseList(head);
    ListNode::print(res);
    ListNode::freeList(res);
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

