/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30202
 *
 * [104] 二叉树的最大深度
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
    // int maxDepth(TreeNode* root) {
    //     if(root==nullptr) return 0;
    //     int left = maxDepth(root->left);
    //     int right = maxDepth(root->right);
    //     return max(left,right) + 1;
    // }
     int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while(!q.empty())
        {
            size_t q_size = q.size();
            for(size_t i =0;i<q_size;i++)
            {
                node = q.front();
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            depth++;
        }
        return depth;

    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({3,9,20,std::nullopt,std::nullopt,15,7});
    int res = solution.maxDepth(root);
    cout<<res<<endl;
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

