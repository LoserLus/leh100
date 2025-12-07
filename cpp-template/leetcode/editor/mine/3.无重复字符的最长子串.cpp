/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30201
 *
 * [3] 无重复字符的最长子串
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        unordered_map<char,int> char_map;
        for(auto c:s)
        {
            char_map[c]=0;
        }
        int left = 0,right = 1;
        int res = 0;
        char_map[s[left]]=1;
        for(;right<s.size();right++)
        {
            char_map[s[right]]++;
            while(char_map[s[right]]>1)
            {
                char_map[s[left]]--;
                left++;
            }
        res = max(res,right-left+1);
            
        }
        return res;

    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string input("pwwkew");
    int res = solution.lengthOfLongestSubstring(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

