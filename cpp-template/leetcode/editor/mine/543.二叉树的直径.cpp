/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30202
 *
 * [543] 二叉树的直径
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
class Solution
{
public:
	int diameterOfBinaryTree(TreeNode *root)
	{
		if (root == nullptr) return 0;
		int max_path = 0;
		getTreeHeight(root,max_path);
		return max_path;
	}
	int getTreeHeight(TreeNode *root,int &max_path)
	{
		if (root == nullptr) return 0;
		int left = getTreeHeight(root->left,max_path);
		int right = getTreeHeight(root->right,max_path);
		max_path = max(max_path, left + right);
		return max(left, right) + 1;
	}
	// int diameterOfBinaryTree(TreeNode* root) {
	//     if(root==nullptr) return 0;
	//     int max_path = 0;
	//     queue<TreeNode*> q;
	//     TreeNode* node = root;
	//     q.push(root);
	//     while(!q.empty())
	//     {
	//         node = q.front();
	//         q.pop();
	//         int left_path = 0;
	//         int right_path = 0;
	//         if(node->left)
	//         {
	//             q.push(node->left);
	//             left_path = getTreeHeight(node->left);
	//         }
	//         if(node->right)
	//         {
	//             q.push(node->right);
	//             right_path = getTreeHeight(node->right);
	//         }
	//         max_path = max(max_path,left_path+right_path);

	//     }
	//     return max_path;

	// }
	// int getTreeHeight(TreeNode* root)
	// {
	//     if(root==nullptr) return 0;
	//     int left = getTreeHeight(root->left);
	//     int right = getTreeHeight(root->right);
	//     return max(left,right)+1;
	// }
};
// @lc code=end

int main()
{
	Solution solution;
	// your test code here
	TreeNode *root = nullptr;
	root = TreeNode::createRoot({1, 2, 3, 4, 5});
	int res = solution.diameterOfBinaryTree(root);
	cout << res << endl;
	TreeNode::freeTree(root);
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
