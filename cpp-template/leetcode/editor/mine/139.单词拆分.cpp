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
        
        // unordered_set <string> wordSet(wordDict.begin(),wordDict.end());
        // bool res = func(s,wordDict,0);
        vector<int> mem(s.size(),-1);
        bool res = func(s,wordDict,mem,0);
        return res;
    }
    // bool func(string& s,  unordered_set<string>& wordSet,vector<int>& mem,int depth)
    // {
    //     if(depth==s.size())
    //     {
    //         return true;
    //     }
    //     if(mem[depth]!=-1) return mem[depth];
    //     bool res = false;
    //     for(int i=depth;i<s.size();i++)
    //     {
    //         string tmp = s.substr(depth,i-depth+1);
    //         if(!wordSet.count(tmp)) continue;
    //         res|=func(s,wordSet,mem,i+1);
    //     }
    //     if(res)mem[depth]=1;
    //     else mem[depth] =0;
    //     return res;
    // }
    bool func(string& s, vector<string>& wordDict,vector<int>& mem,int depth)
    {
        if(depth==s.size())
        {
            return true;
        }
        if(mem[depth]!=-1) return mem[depth];
        bool res = false;
        for(int i=0;i<wordDict.size();i++)
        {
            int word_size = wordDict[i].size();
            string tmp = s.substr(depth,word_size);
            if(tmp!=wordDict[i]) continue;
            res|=func(s,wordDict,mem,depth+word_size);
        }
        if(res) mem[depth]=1;
        else mem[depth]=0;
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
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

