/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30201
 *
 * [438] 找到字符串中所有字母异位词
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()==1)
        {
            if(p.size()==1) return s[0]==p[0]? vector<int> {0}:vector<int>{};
            return vector<int>{};
        }
        size_t l_p =0,w=p.size();
        vector<int> res;
        vector<int> s_count(26,0);
        vector<int> p_count(26,0);
        for(auto c:p)
        {
            p_count[c-'a'] = p_count[c-'a'] + 1;
        }
        for(;l_p+w<s.size();l_p++)
        {
            if(condition(s,p,l_p,w))
            {
                res.push_back(l_p);
            }
        }
        return res;
    }
    bool condition(vector<int>&s_count, string& s,const vector<int>& p_count,size_t l_p,size_t w)
    {
        bool res = true;
        for(size_t i=0;i<w;i++)
        {
            bool flag = false;
            for(size_t j=0;j<p.size();j++)
            {
                if(s[l_p+ i]==p[j])
                {
                    flag = true;
                    break;
                }
            }
            res &= flag;
        }
        return res;
    }   
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string input("cbaebabacd");
    string p("abc");
    vector<int> res = solution.findAnagrams(input,p);
    //test
    print_vec(res);
    
}



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */

