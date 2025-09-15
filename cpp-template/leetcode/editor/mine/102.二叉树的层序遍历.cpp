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
      if(root==nullptr) return vector<vector<int>>{};
      queue<TreeNode*> q;
      vector<vector<int>> res;
      q.push(root);
      while(!q.empty())
      {
        int q_size = q.size();
        vector<int> vec;
        while(q_size--)
        {
            TreeNode* p = q.front();
            q.pop();
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
            vec.push_back(p->val);
        }
        res.push_back(vec);
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

