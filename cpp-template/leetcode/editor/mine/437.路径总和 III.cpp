/*
 * @lc app=leetcode.cn id=437 lang=cpp
 * @lcpr version=30202
 *
 * [437] 路径总和 III
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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

    
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        unordered_map<long long,int> hashmap;
        hashmap[0] = 1;
        func(root,targetSum,0,hashmap);
        return res;
    }
   
    void func(TreeNode* root, int targetSum, long long sum, unordered_map<long long,int>& hashmap)
    {
        if(root==nullptr) return;
        sum = sum + root->val;
        auto it = hashmap.find(sum-targetSum);
        if(it!= hashmap.end())
        {
            res+=it->second;
        }
        it = hashmap.find(sum);
        if(it!=hashmap.end())
        {
            hashmap[sum]+=1;
        }
        else{
            hashmap[sum] = 1;
        }
        if(root->left!=nullptr) func(root->left,targetSum,sum,hashmap);
        if(root->right!=nullptr) func(root->right,targetSum,sum,hashmap);
        hashmap[sum]-=1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    #define null std::nullopt
    TreeNode* root = nullptr;
    root = TreeNode::createRoot({5,4,8,11,null,13,4,7,2,null,null,5,1});
    TreeNode::print(root);
    int k = 22;
    int res = solution.pathSum(root,k);
    cout<<res<<endl;
    TreeNode::freeTree(root);
}



/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */

