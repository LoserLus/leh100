/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30201
 *
 * [3] 无重复字符的最长子串
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        if(s.size() == 2) return s[0]==s[1]?1:2;

        size_t l_p = 0;
        size_t f_p = 0;
        int max_len = 0;
        int len = 0;
        for(;f_p<s.size();f_p++)
        {
            while (l_p<f_p&& k_in_sbstr(s,l_p,f_p,s[f_p]))
            {
                l_p++;
            }
            len = f_p - l_p + 1;
            max_len = max(max_len,len);
        }
        return max_len;
        // size_t l_p = 0;
        // size_t f_p = 0;
        // int max_len = 0;
        // int len = 0;
        // while(l_p<s.size())
        // {
        //     f_p = l_p+1;
        //     while (f_p<s.size()&&! k_in_sbstr(s,l_p,f_p,s[f_p])) 
        //     {
        //         f_p++;
        //     }
        //     len = f_p - l_p;
        //     max_len = max(max_len,len);
        //     l_p ++;
        
        // }
        // return max_len;
    }
    bool k_in_sbstr(const string& s,size_t l_p,size_t r_p,const char k)
    {
        for(size_t i =l_p;i<r_p;i++)
            {
                if(s[i]==k) return true;
            }
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string input("abcabcbb");
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

