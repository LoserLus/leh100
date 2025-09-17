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
   
    vector<vector<int>> subsets(vector<int>& nums) {
       if(nums.size()<=1) return vector<vector<int>> {{},{nums}};
       vector<vector<int>> res;
       vector<int> vec;
       func(res,nums,vec,0);
       return res;
    }
    
    void func(vector<vector<int>>& res,vector<int>& nums,vector<int>& vec,int depth)
    {
        res.push_back(vec);
        if(depth==nums.size()) return;
        for(int i=depth;i<nums.size();i++)
        {
            vec.push_back(nums[i]);
            func(res,nums,vec,i+1);
            vec.pop_back();
        }
    }
    
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({1});
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

