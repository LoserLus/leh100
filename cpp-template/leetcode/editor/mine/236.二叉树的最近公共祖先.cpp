/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30202
 *
 * [236] 二叉树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        vector<TreeNode*> p_vec,q_vec;
        func(root,p,p_vec);
        func(root,q,q_vec);
        // cout<<"p_vec size "<<p_vec.size()<<endl;
        // cout<<"q_vec size "<<q_vec.size()<<endl;
        size_t i = 0;
        for(;i<min(q_vec.size(),p_vec.size());i++)
        {
            // cout<<"p_vec ["<<i<<"]"<<p_vec[i]<<endl;
            // cout<<"q_vec ["<<i<<"]"<<q_vec[i]<<endl;
            if(q_vec[i]!=p_vec[i])
                break;   
        }
        return q_vec[i-1];
    }
    bool func(TreeNode* root, TreeNode* target,vector<TreeNode*>& vec)
    {
        if(root==nullptr) return false;
        if(vec.size()>0&&vec[vec.size()-1]==target) return true;
        if(root==target){
            vec.push_back(root);
            return true;
        }
        vec.push_back(root);
        bool left =  func(root->left,target,vec);
        bool right = func(root->right,target,vec);
        if(left|| right)
        {
            return true;
        }
        vec.pop_back();
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    #define null std::nullopt
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({3,5,1,6,2,0,8,null,null,7,4});
    TreeNode::print(root);
    TreeNode* q = nullptr;
    TreeNode* p = nullptr;
    q = TreeNode::findVal(root,5);
    p = TreeNode::findVal(root,1);
    TreeNode* res  = solution.lowestCommonAncestor(root,q,p);
    // cout<<res<<endl;
    TreeNode::print(res);
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

