/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30202
 *
 * [94] 二叉树的中序遍历
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"
#include<stack>
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
vector<int> inorderTraversal(TreeNode* root){
    if(root==nullptr) return vector<int> {};
    vector<int> vec;
    stack<TreeNode*> s;
    TreeNode* node = root;
    while(node!=nullptr||!s.empty())
    {
       if(node!=nullptr)
       {
        s.push(node);
        node=node->left;
       }
       else
       {
        node = s.top();
        s.pop();
        vec.push_back(node->val);
        node = node->right;
       }
    }
    return vec;
}
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res ;
    //     fun(res,root);
    //     return res;
    // }
    // void fun(vector<int>& v,TreeNode* node)
    // {
    //     if(node==nullptr) return;
    //     fun(v,node->left);
    //     v.push_back(node->val);
    //     fun(v,node->right);
    // }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({1,std::nullopt,2,3});
    vector<int> res = solution.inorderTraversal(root);
    print_vec<int>(res);
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

