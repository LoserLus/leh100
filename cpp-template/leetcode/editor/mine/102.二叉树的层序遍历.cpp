/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30202
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>> {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        TreeNode* node = root;
        q.push(node);
        while(!q.empty())
        {
            vector<int> tmp;
            size_t q_size = q.size();
            for(size_t i =0;i<q_size;i++)
            {
                node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({3,9,20,std::nullopt,std::nullopt,15,7});
    vector<vector<int>> res = solution.levelOrder(root);
    print_vec_2d<int>(res);
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

