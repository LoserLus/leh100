/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30202
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return true;
        vector<int> vec;
        ListNode* node = head;
        while(node!=nullptr)
        {
            vec.push_back(node->val);
            node = node->next;
        }
        for(size_t i=0,j=vec.size()-1;i<=j;i++,j--)
        {
            if(vec[i]!=vec[j]) return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    ListNode* head = ListNode::createHead({1,2});
    bool res = solution.isPalindrome(head);
    cout<<res<<endl;
    ListNode::freeList(head);
}



/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

