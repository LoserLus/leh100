/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30202
 *
 * [101] 对称二叉树
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
bool isSymmetric(TreeNode* root) 
{
    if(root==nullptr) return false;
    return func(root->left,root->right);
}
bool func(TreeNode* lnode,TreeNode*rnode)
{
    if(lnode==nullptr && rnode==nullptr) return true;
    if(lnode==nullptr || rnode==nullptr) return false;
    if(lnode->val == rnode->val)
    {
        return func(lnode->left,rnode->right) && func(lnode->right,rnode->left);
    }
    else return false;
}
    // bool isSymmetric(TreeNode* root) {
    //     if(root == nullptr) return false;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     TreeNode* node;
    //     TreeNode null_node(-101);
    //     while(!q.empty())
    //     {
    //         size_t q_size = q.size();
    //         vector<int> vec;
    //         for(size_t i=0;i<q_size;i++)
    //         {
    //             node = q.front();
    //             q.pop();
    //             vec.push_back(node->val);
    //             // 第二次遇到直接不处理
    //             if(node==&null_node) continue;
    //             // 第一次遇到缺少节点就加一个空节点
    //             if(node->left!=nullptr) q.push(node->left);
    //             else q.push(&null_node);
    //             if(node->right!=nullptr) q.push(node->right);
    //             else q.push(&null_node);
    //         }
    //         size_t l_p=0,r_p = vec.size()-1;
    //         bool flag = true;
    //         while(flag&&(l_p<r_p))
    //         {
    //             if(vec[l_p]!=vec[r_p]) flag=false;
    //             l_p++;
    //             r_p--;
    //         }
    //         if(flag==false) return false;
    //     }
    //     return true;
    // }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({1,2,2,3,4,4,3});
    bool res = solution.isSymmetric(root);
    cout<<res<<endl;
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

