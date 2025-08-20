/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30202
 *
 * [145] 二叉树的后序遍历
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* node=root;
        while(node!=nullptr||!s.empty())
        {
            while(node!=nullptr)
            {
                res.push_back(node->val);
                s.push(node->left);
                node=node->right;
            }
            node = s.top();
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({1,std::nullopt,2,3});
    vector<int> res = solution.postorderTraversal(root);
    print_vec<int>(res);
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

