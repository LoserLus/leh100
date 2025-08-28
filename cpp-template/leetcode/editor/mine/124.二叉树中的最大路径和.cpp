/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=30202
 *
 * [124] 二叉树中的最大路径和
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
    int res = -(1U << (sizeof(int) * 8 - 1));
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        func(root);
        return res;
    }
    int func(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int left = func(root->left);
        int right = func(root->right);
        int path_max = max(left,0)+max(right,0)+root->val;
        res = max(res,path_max);
        return max({left,right,0})+root->val;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    #define null std::nullopt
    root = TreeNode::createRoot({-10,9,20,null,null,15,7});
    int res = solution.maxPathSum(root);
    cout<<res<<endl;
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */

