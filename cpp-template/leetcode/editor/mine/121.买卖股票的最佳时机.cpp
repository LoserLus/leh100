/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30201
 *
 * [121] 买卖股票的最佳时机
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> dp(prices.size(),0);
        int min_price = prices[0];
        for(int i = 1;i<dp.size();i++)
        {
            min_price = min(prices[i],min_price);
            dp[i] = max(dp[i-1],prices[i]-min_price);
        }
        return dp[dp.size()-1];
        
        // vector<int> dp(prices.size(),0);
        // for(int i = 1;i<dp.size();i++)
        // {
        //     dp[i] = dp[i-1];
        //     for(int j=0;j<i;j++)
        //     {
        //         dp[i] = max(dp[i],prices[i]-prices[j]);
        //     }
        // }
        // return dp[dp.size()-1];


        // int max_profit = 0;
        // for(int i=0;i<prices.size()-1;i++)
        // {
        //     int in_p = prices[i];
        //     for(int j=i+1;j<prices.size();j++)
        //     {
        //         int out_p = prices[j];
        //         if (out_p <= in_p) continue;
        //         else
        //         {
        //             int profit = out_p - in_p;
        //             if (profit > max_profit) max_profit = profit;
        //         }
        //     }
        // }
        // return max_profit;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({7,1,5,3,6,4});
    int res = solution.maxProfit(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

