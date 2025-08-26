/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30202
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        func(root,k,vec);
        return vec[k-1];
    }

    void func(TreeNode* root, int k,vector<int>& vec)
    {
        if(root == nullptr) return ;
        if(vec.size()>=k) return;
        func(root->left,k,vec);
        vec.push_back(root->val);
        func(root->right,k,vec);

    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({5,3,6,2,4,std::nullopt,std::nullopt,1});
    int k = 3;
    int res = solution.kthSmallest(root,k);
    cout<<res<<endl;
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */

