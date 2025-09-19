/*
 * @lc app=leetcode.cn id=138 lang=cpp
 * @lcpr version=30203
 *
 * [138] 随机链表的复制
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

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        unordered_map<Node*,Node*> hash_map;
        Node* p = head;
        while(p)
        {
            hash_map[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        while(p)
        {
            hash_map[p]->next = hash_map[p->next];
            hash_map[p]->random = hash_map[p->random];
            p = p->next;
        }
        return hash_map[head];
    }
    // Node *copyRandomList(Node *head)
    // {
    //     if (head == nullptr)
    //         return nullptr;
    //     vector<Node *> vec;
    //     Node *p = head;
    //     int cnt = 0;
    //     unordered_map<Node *, int> hash_map;
    //     while (p)
    //     {
    //         hash_map[p] = cnt;
    //         vec.push_back(new Node(p->val));
    //         p = p->next;
    //         cnt++;
    //     }
    //     p = head;
    //     vec.push_back(nullptr);

    //     for (int i = 0; i < vec.size() - 1; i++)
    //     {
    //         if (p->random)
    //         {
    //             int index = hash_map[p->random];
    //             vec[i]->random = vec[index];
    //         }
    //         else
    //             vec[i]->random = nullptr;
    //         vec[i]->next = vec[i + 1];
    //         p = p->next;
    //     }
    //     return vec[0];
    // }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */
