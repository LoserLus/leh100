/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30202
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map <ListNode*,int> hashmap;
        ListNode* node = headA;
        while(node!=nullptr)
        {
            hashmap[node] = 1;
            node = node->next;
        }
        node = headB;
        while(node!=nullptr)
        {
            auto it = hashmap.find(node);
            if(it!=hashmap.end())
            {
                return it->first;
            }
            node=node->next;
        }
        return nullptr;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    ListNode* headA = ListNode::createHead({4,1,});
    ListNode* headB = ListNode::createHead({5,6,1});
    ListNode* headC = ListNode::createHead({8,4,5});
    ListNode* node_a = headA;
    while(node_a->next!=nullptr) node_a = node_a ->next;
    node_a->next = headC;
     ListNode* node_b = headB;
    while(node_b->next!=nullptr) node_b = node_b ->next;
    node_b->next = headC;
    ListNode* res = solution.getIntersectionNode(headA,headB);
    ListNode::print(res);
    node_a->next = nullptr;
    node_b->next = nullptr;
    ListNode::freeList(headA);
    ListNode::freeList(headB);
    ListNode::freeList(headC);
}



/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */

