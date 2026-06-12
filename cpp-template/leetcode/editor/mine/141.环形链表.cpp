/*
 * @lc app=leetcode.cn id=141 lang=cpp
 * @lcpr version=30202
 *
 * [141] 环形链表
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head==nullptr||head->next==nullptr) return false;
        auto* fast = head->next->next;
        auto* slow = head;
        while(fast && fast->next)
        {
            if(slow==fast) return true;
            slow=slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */

