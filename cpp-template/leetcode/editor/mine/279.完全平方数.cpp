/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=30201
 *
 * [279] 完全平方数
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/utils.cpp"


using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        if(n<=3) return n;

        vector <int> dp(n+1,0);
        for(size_t i = 1;i<dp.size();i++)
        {
            dp[i] = i;
        }
        for(size_t i = 1;i<dp.size();i++)
        {
            for(size_t j=1;j*j<=i;j++)
            {
                if(i>=j*j)
                    dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
        // vector<int> nums;
        // nums.push_back(0);
        // int num=1;
        // for(;num*num<=n;num++)
        // {
        //     nums.push_back(num*num);
        // }
        // vector<vector<int>> dp(num,vector<int>(n+1,n));
        // for(int j=1;j<=n;j++)
        // {
        //     dp[1][j]=j;
        // }
        // for(int i=1;i<num;i++)
        // {
        //     dp[i][0] = 0;
        //     dp[i][1] = 1;
        //     dp[i][2] = 2;
        //     dp[i][3] = 3;
        //     for(auto num:nums)
        //         dp[i][num] = 1;
        // } 
        
        // for(int j=4;j<=n;j++)
        
        // {
        //     for(int i=2;i<num;i++)
        //     {
        //         if(j-nums[i]>0)
        //             {
        //                 dp[i][j] = min(dp[i-1][j],1+dp[i][j-nums[i]]);
        //             }
        //         else
        //             dp[i][j] = dp[i-1][j];
        //     }
        // }
        // return dp[num-1][n];
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    int input = 12;
    int res = solution.numSquares(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */

