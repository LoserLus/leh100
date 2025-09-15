/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 * @lcpr version=30203
 *
 * [1143] 最长公共子序列
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()==0||text2.size()==0) return 0;
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else 
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string input1 = "abcde";
    string input2 = "ace";
    int res = solution.longestCommonSubsequence(input1,input2);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */

