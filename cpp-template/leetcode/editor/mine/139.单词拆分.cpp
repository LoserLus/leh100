/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30203
 *
 * [139] 单词拆分
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> word_set(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        for(int i=1;i<dp.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                string tmp = s.substr(j,i-j);
                dp[i] |= dp[j]&&word_set.count(tmp);
            }
        }
        return dp[dp.size()-1]==1?true:false;
    }
 
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    bool res = solution.wordBreak(s,wordDict);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */

