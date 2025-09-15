/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30202
 *
 * [142] 环形链表 II
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
 ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while(fast&&fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast)
            {
                while(pre!=slow)
                {
                    pre = pre->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
    // ListNode *detectCycle(ListNode *head) {
    //     if(head==nullptr || head->next==nullptr) return nullptr;
    //     unordered_map<ListNode*,int> hashmap;
    //     ListNode* node = head;
    //     while(node)
    //     {
    //         auto it = hashmap.find(node);
    //         if(it!=hashmap.end())
    //         {
    //             return it->first;
    //         }
    //         hashmap[node] = 1;
    //         node = node ->next;
    //     }
    //     return nullptr;
    // }
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

