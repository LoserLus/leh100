/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30201
 *
 * [70] 爬楼梯
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
    int climbStairs(int n) {
        if (n ==1 ) return 1;
        if ( n==2 ) return 2;
        vector<int> dp(n,0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2;i<n;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    int input = 3;
    int res = solution.climbStairs(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

