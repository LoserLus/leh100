/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30201
 *
 * [300] 最长递增子序列
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1) return 1;
        vector<int> dp(nums.size(),1);
        for (size_t i = 1; i < dp.size(); i++)
        {
            for(size_t j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
    
        }
        
        for (size_t i = 1; i < dp.size(); i++)
        {
            if(nums[i]>nums[i-1])
                dp[i] = max(dp[i-1],dp[i]);
            else
                dp[i]=dp[i-1];
        }
        
        return dp[nums.size()-1];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
     vector<int> input({0,1,0,3,2,3});
    int res = solution.lengthOfLIS(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */

