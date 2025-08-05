/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30201
 *
 * [322] 零钱兑换
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
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> coins_new;
        coins_new.push_back(0);
        for(auto coin : coins)
        {
            if (coin<=amount)
                coins_new.push_back(coin);
        }
        if(coins_new.size()<2) return -1;

        vector<int> dp(amount+1,10001);
       
        for(auto coin:coins_new)
        {
            dp[coin] = 1;
        }
        dp[0] = 0;
        for(size_t i=1;i<=amount;i++)
        {
            for(size_t j=1;j<coins_new.size();j++)
            {
                if(coins_new[j]<=i)
                {
                    dp[i] = min(dp[i],dp[i-coins_new[j]]+1);
                }
            }
        }
        return dp[amount] == 10001?-1:dp[amount];
        // vector<vector<int>> dp(coins_new.size(),vector<int>(amount+1,10001));
        // for(size_t j=1;j<=amount;j++)
        // {
        //     if(j%coins_new[1] == 0)
        //         dp[1][j] = int(j/coins_new[1]);
        // }
        // for(size_t i =1;i<dp.size();i++)
        // {
        //     dp[i][0] = 0;
        //     for(size_t j =1;j<coins_new.size();j++)
        //         dp[i][coins_new[j]] = 1;
        // }
       
        // for(size_t j=1;j<=amount;j++)
        // {
        //     for(size_t i=1;i<dp.size();i++)
        //     {
        //         if(j>=coins_new[i])
        //             dp[i][j]=min(dp[i-1][j],dp[i][j-coins_new[i]]+1);
        //          else
        //             dp[i][j] = dp[i-1][j];
        //     }
        // }
        // return dp[dp.size()-1][amount]==10001?-1:dp[dp.size()-1][amount];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({1,2,5});
    int amount = 11;
    int res = solution.coinChange(input,amount);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

