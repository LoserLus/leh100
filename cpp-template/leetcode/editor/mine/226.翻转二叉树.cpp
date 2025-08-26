/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30202
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        func(root);
        return root;
    }
    void func(TreeNode* root)
    {
        if (root==nullptr) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        func(root->left);
        func(root->right);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({4,2,7,1,3,6,9});
    root = solution.invertTree(root);
    TreeNode::print(root);
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

