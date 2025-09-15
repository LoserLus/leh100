/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30202
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        ListNode dummy(0);
        ListNode* res_p = &dummy;
        while (list1&&list2)
        {
            if(list1->val<=list2->val)
            {
                res_p->next = list1;
                list1 = list1->next;
            }
            else{
                res_p->next = list2;
                list2 = list2->next;
            }
            res_p = res_p->next;
        }
        if(list1) res_p->next = list1;
        else res_p->next = list2;
        return dummy.next;
        
    }
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if(list1==nullptr) return list2;
    //     if(list2==nullptr) return list1;
    //     ListNode* head = nullptr;
    //     ListNode* head_p = nullptr;
    //     ListNode* list1_p = nullptr;
    //     ListNode* list2_p = nullptr;
    //     list1_p = list1;
    //     list2_p = list2;
    //     if(list1_p->val <= list2_p->val)
    //     {
    //         head = new ListNode(list1_p->val);
    //         list1_p = list1_p->next;
    //     }
    //     else{
    //         head = new ListNode(list2_p->val);
    //         list2_p = list2_p->next;
    //     }
    //     head_p = head;
    //     while (list1_p!=nullptr&&list2_p!=nullptr)
    //     {
    //         if(list1_p->val <= list2_p->val)
    //         {
    //             ListNode* node = new ListNode(list1_p->val);
    //             head_p -> next = node;
    //             list1_p = list1_p->next;
    //         }
    //         else
    //         {
    //             ListNode* node = new ListNode(list2_p->val);
    //             head_p -> next = node;
    //             list2_p = list2_p->next;
    //         }
    //         head_p = head_p->next;
            
    //     }
    //     if(list1_p==nullptr)
    //     {
    //         while(list2_p!=nullptr)
    //         {
    //             ListNode* node = new ListNode(list2_p->val);
    //             head_p -> next = node;
    //             list2_p = list2_p->next;
    //             head_p = head_p->next;
    //         }
    //     }
    //     else
    //     {
    //         while(list1_p!=nullptr)
    //         {
    //             ListNode* node = new ListNode(list1_p->val);
    //             head_p -> next = node;
    //             list1_p = list1_p->next;
    //             head_p = head_p->next;
    //         }
    //     }
    //     return head;
    // }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    ListNode* input = ListNode::createHead({1,2,4});
    ListNode* input2 = ListNode::createHead({1,3,4});
    ListNode* res = solution.mergeTwoLists(input,input2);
    ListNode::print(res);
    ListNode::freeList(input);
    ListNode::freeList(input2);
    ListNode::freeList(res);
}



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */

