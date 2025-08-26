/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30202
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        if(nums.size()==1) return new TreeNode(nums[0]);
        TreeNode* root = func(nums,0,nums.size()-1);
        return root;
    }
    TreeNode* func(vector<int>& nums,int left,int right)
    {
        if(left>right) return nullptr;
        int mid = left + ((right - left) /2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = func(nums,left,mid-1);
        root->right = func(nums,mid+1,right);
        return root;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    vector<int> input = {-10,-3,0,5,9};
    root = solution.sortedArrayToBST(input);
    TreeNode::print(root);
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */

