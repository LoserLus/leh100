/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30201
 *
 * [198] 打家劫舍
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/utils.cpp"


using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i=2;i<dp.size();i++)
        {
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[dp.size()-1];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({2,7,9,3,1});
    int res = solution.rob(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */

