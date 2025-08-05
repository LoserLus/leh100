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
        int maxInt = (1U << (sizeof(int) * 8 - 1)) - 1; // 2^(n-1) - 1
        int minInt = -(1U << (sizeof(int) * 8 - 1));    // -2^(n-1)
        vector<int> dp(nums.size(),minInt);
        vector<int> maxdp(nums.size(),minInt);
        vector<int> mindp(nums.size(),maxInt);
        dp[0] = nums[0];
        maxdp[0] = nums[0];
        mindp[0] = nums[0];
        
        for(size_t i=1;i<dp.size();i++)
        {
            if(nums[i]==0)
            {
                maxdp[i] = 0;
                mindp[i] = 0;
            }
            else{
                maxdp[i] = max({nums[i],nums[i]*maxdp[i-1],nums[i]*mindp[i-1]});
                mindp[i] = min({nums[i],nums[i]*maxdp[i-1],nums[i]*mindp[i-1]});
            }
            dp[i] = max({dp[i-1],maxdp[i]});
            
        }
        return dp[nums.size()-1];
        
        // vector<vector<int>> result(nums.size(),vector<int>(nums.size(),1));
        // auto sum = [&nums](size_t i,size_t j)->int{
        //     int r=1;
        //     for(size_t k = i;k<j;k++)
        //     {
        //         r*=nums[k];
        //     }
        //     return r;
        // };
        // for(size_t i = 0;i<nums.size();i++)
        // {
        //     for(size_t j=0;j<nums.size();j++)
        //     {
        //         result[i][j] = sum(i,j);
        //     }
        // }
        // vector<int> dp(nums.size(),1);
        // dp[0] = nums[0];
        // for(size_t i=1;i<dp.size();i++)
        //     {
        //         for(size_t j =0;j<i;j++)
        //         {
        //             dp[i] = max(dp[i],result[j][i]);
        //         }
        //     }
        // return *max_element(dp.begin(),dp.end());
        
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

