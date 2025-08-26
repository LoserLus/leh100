/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=30202
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
       if(root==nullptr) return vector<int> {};
       queue<TreeNode*> q;
       q.push(root);
       TreeNode* node = nullptr; 
       vector<int> res;
       while(!q.empty())
       {
        size_t q_size = q.size();
        for(size_t i =0;i<q_size;i++)
        {
            node = q.front();
            q.pop();
            if(i==0)
                res.push_back(node->val);
            if(node->right!=nullptr) q.push(node->right);
            if(node->left!=nullptr) q.push(node->left);
        }
       }
       return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({1,2,3,4,std::nullopt,std::nullopt,std::nullopt,5});
    vector<int> res = solution.rightSideView(root);
    print_vec<int>(res);
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,null,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

