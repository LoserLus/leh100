/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30202
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* node = &dummy;
        ListNode* pre = node;

        while (node)
        {
            
            while(pre)
           node = node->next;
        }
        return dummy.next;
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    ListNode* input = ListNode::createHead({4,2,1,3});
    ListNode* res = solution.sortList(input);
    ListNode::print(res);
    ListNode::freeList(res);
}



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

