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
        if(head==nullptr||head->next==nullptr) return head;
        ListNode dummy;
        ListNode* p;
        p = head;
        while(p)
        {
            ListNode* tmp = p->next;
            p->next = dummy.next;
            dummy.next = p;
            p = tmp;
        }
        return dummy.next;
    }
};
// @lc code=end
ListNode* tail_insert(const vector<int>& vals)
{
    if(vals.size()==0) return nullptr;
    ListNode dummy;
    ListNode* p = new ListNode(vals[0]);
    p->next = nullptr;
    dummy.next = p;   
    for(int i=1;i<vals.size();i++)
    {
        p = new ListNode(vals[i]);
        p ->next = nullptr;
        ListNode* tail = dummy.next;
        while(tail->next!=nullptr) tail = tail->next;
        tail -> next = p;
    }
    return dummy.next;
}
int main() {
    Solution solution;
    // your test code here
    ListNode* head = tail_insert({1,2,3,4,5});
    ListNode::print(head);
    // ListNode* head = ListNode::createHead({1,2,3,4,5});
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

