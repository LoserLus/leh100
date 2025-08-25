/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30202
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        vector<int> vec;
        func(root,vec);
        if(vec.size()==1) return true;
        for(size_t i = 1;i<vec.size();i++)
        {
            if(vec[i-1]>=vec[i]) return false;
        }
        return true;
    }
    void func(TreeNode* root,vector<int>& vec)
    {
        if(root == nullptr) return;
        func(root->left,vec);
        vec.push_back(root->val);
        func(root->right,vec);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({2,1,3});
    bool res = solution.isValidBST(root);
    cout<<res<<endl;
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

