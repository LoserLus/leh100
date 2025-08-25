/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30202
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        if(preorder.size()==1) return new TreeNode(preorder[0]);
        TreeNode* root = build(preorder,inorder);
        return root;
    }
    TreeNode* build(vector<int>& preorder,vector<int>& inorder)
    {
        if(preorder.size()==0) return nullptr;
        TreeNode* root = new TreeNode();
        root->val = preorder[0];
        if(preorder.size()==1)
        {
            root->left=nullptr;
            root->right=nullptr;
            return root;
        }
        auto it = find(inorder.begin(),inorder.end(),root->val);
        size_t index = 0;
        if(it!=inorder.end())
        {
            index = distance(inorder.begin(),it);
        }
        vector<int> left_inorder(inorder.begin(),inorder.begin()+index);
        vector<int> right_inorder(inorder.begin()+index+1,inorder.end());
        vector<int> left_preorder(preorder.begin()+1,preorder.begin()+1+left_inorder.size());
        vector<int> right_preorder(preorder.begin()+1+left_inorder.size(),preorder.end());
        root->left = build(left_preorder,left_inorder);
        root->right = build(right_preorder,right_inorder);
        return root;

    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    root = solution.buildTree(preorder,inorder);
    TreeNode::print(root);
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

