/*
 * @lc app=leetcode.cn id=118 lang=cpp
 * @lcpr version=30201
 *
 * [118] 杨辉三角
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/utils.cpp"


using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp ;
        for (int i=0;i<numRows;i++)
        {
            vector<int> tmp(i+1,1);
            dp.push_back(tmp);
        }
        for(int i =2;i<numRows;i++)
        {
            for(int j=1;j<i;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
        return dp;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    int input = 5;
    vector<vector<int>> res = solution.generate(input);
    print_vec_2d(res);
}



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

