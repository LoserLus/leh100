/*
 * @lc app=leetcode.cn id=152 lang=cpp
 * @lcpr version=30201
 *
 * [152] 乘积最大子数组
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max({nums[0],nums[1],nums[0]*nums[1]});
        vector<int> min_dp(nums.size(),INT32_MAX);
        vector<int> max_dp(nums.size(),INT32_MIN);
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        min_dp[0] = nums[0];
        max_dp[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                min_dp[i] = 0;
                max_dp[i] = 0;
            }
            else
            {
                max_dp[i] = max({nums[i],nums[i]*max_dp[i-1],nums[i]*min_dp[i-1]});
                min_dp[i] = min({nums[i],nums[i]*max_dp[i-1],nums[i]*min_dp[i-1]});
            }
            dp[i] = max(dp[i-1],max_dp[i]);
        }
        return dp[nums.size()-1];
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({-1,-2,-9,-6});
    int res = solution.maxProduct(input);
    cout<<res<<endl;
    

}



/*
// @lcpr case=start
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

 */

