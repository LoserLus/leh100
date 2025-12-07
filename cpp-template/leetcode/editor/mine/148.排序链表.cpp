/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30202
 *
 * [148] 排序链表
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
        vector<ListNode*> vec;
        ListNode* node = head;
        while (node)
        {
            vec.push_back(node);
            node = node->next;
        }

        sort(vec.begin(),vec.end(),[](ListNode* n1,ListNode* n2)->bool {return n1->val<n2->val;});
        for(int i=0;i<vec.size()-1;i++)
        {
            vec[i]->next = vec[i+1];
        }
        vec[vec.size()-1]->next = nullptr;
        return vec[0];
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

