/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30202
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* left = head;
        ListNode* right = nullptr;
        while(left&&left->next)
        {
            right = left->next;
            pre->next = right;
            left->next = right->next;
            right->next = left;
            pre = left;
            left = left->next;
        }
        return dummy.next;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    ListNode* input = ListNode::createHead({1});
    ListNode* res = solution.swapPairs(input);
    ListNode::print(res);
    ListNode::freeList(res);
}



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

