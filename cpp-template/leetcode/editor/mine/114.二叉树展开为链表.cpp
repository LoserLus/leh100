/*
 * @lc app=leetcode.cn id=114 lang=cpp
 * @lcpr version=30202
 *
 * [114] 二叉树展开为链表
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 void flatten(TreeNode* root) {
        if(root==nullptr) return;
        vector<TreeNode*> vec;
        
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* node = nullptr;
        while(!s.empty())
        {
            node = s.top();
            s.pop();
            vec.push_back(node);
            if(node->right!=nullptr) s.push(node->right);
            if(node->left!=nullptr) s.push(node->left);
        }

        for(size_t i = 0;i<vec.size()-1;i++)
        {
            vec[i]->left = nullptr;
            vec[i]->right = vec[i+1];
        }
    }

    //     void flatten(TreeNode* root) {
    //     if(root==nullptr) return;
    //     vector<TreeNode*> vec;
        
    //     stack<TreeNode*> s;
    //     s.push(root);
    //     TreeNode* node = nullptr;
    //     while(!s.empty()||node!=nullptr)
    //     {
    //         while(node!=nullptr)
    //         {
    //             // node = s.top();
    //             // s.pop();
    //             vec.push_back(node);
    //             s.push(node->right);
    //             node = node ->left;
    //         }
    //         node = s.top();
    //         s.pop();
    //     }

    //     for(size_t i = 0;i<vec.size()-1;i++)
    //     {
    //         vec[i]->left = nullptr;
    //         vec[i]->right = vec[i+1];
    //     }
    // }

    // void flatten(TreeNode* root) {
    //     if(root==nullptr) return;
    //     vector<TreeNode*> vec;
    //     func(vec,root);
    //     for(size_t i = 0;i<vec.size()-1;i++)
    //     {
    //         vec[i]->left = nullptr;
    //         vec[i]->right = vec[i+1];
    //     }

    // }
    // void func(vector<TreeNode*>& vec,TreeNode* root)
    // {
    //     if(root==nullptr) return;
    //     vec.push_back(root);
    //     func(vec,root->left);
    //     func(vec,root->right);
    // }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
      TreeNode* root = nullptr;
    root = TreeNode::createRoot({1,2,5,3,4,std::nullopt,6});
    solution.flatten(root);
    TreeNode::print(root);
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

