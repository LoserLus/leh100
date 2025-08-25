/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30202
 *
 * [46] 全排列
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
    vector<int> vis;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0) return vector<vector<int>> {};
        if(nums.size()==1) return vector<vector<int>> {vector<int>{nums[0]}};
        
        for(size_t i =0;i<nums.size();i++)
            vis.push_back(0);
        vector<int> vec;
        func(nums,vec);
        return res;
        
    }
    void func(vector<int>& nums,vector<int>& vec)
    {
        if(vec.size() == nums.size())
        {
            res.push_back(vec);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(vis[i]) continue;
            vec.push_back(nums[i]);
            vis[i] = 1;
            func(nums,vec);
            vis[i] = 0;
            vec.pop_back();
        }
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({1,2,3});
    vector<vector<int>> res = solution.permute(input);
    print_vec_2d(res);
}



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

