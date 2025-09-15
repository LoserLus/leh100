/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30203
 *
 * [5] 最长回文子串
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++)
        {
            dp[i][i] = 1;
        }
        for(int i=s.size()-1;i>-1;i--)
        {
            for(int j = i;j<s.size();j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i<2) dp[i][j] = 1;
                    else if(dp[i+1][j-1]==1) dp[i][j]=1;
                }
            }
        }
        int max_len =0;
        string max_str;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(dp[i][j]==0) continue;
                if(j-i+1>max_len)
                {
                    max_len = j-i+1;
                    max_str = s.substr(i,max_len);
                }
            }
        }
        return max_str;
    }
 
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string input = "aacabdkacaa";
    string res = solution.longestPalindrome(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

