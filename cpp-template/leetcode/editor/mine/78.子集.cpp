/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30202
 *
 * [78] 子集
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back(vector<int>{});
        if(nums.size()==0) return res;
        if(nums.size()==1) {res.push_back(vector<int>{nums[0]});return res;}
        vector<int> vis(nums.size(),0);
        vector<int> vec;
        dfs(nums,vis,vec,0);
        return res;

    }
    void dfs(vector<int>& nums,vector<int>& vis,vector<int>& vec, int depth)
    {
        if(depth == nums.size()) return;
        for(size_t i = depth;i<nums.size();i++)
        {
            if(vis[i]) continue;
            vis[i] = 1;
            vec.push_back(nums[i]);
            res.push_back(vec);
            dfs(nums,vis,vec,i);
            vec.pop_back();
            vis[i] = 0;
        }

    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({1,2,3});
    vector<vector<int>> res = solution.subsets(input);
    print_vec_2d<int>(res);
}



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

