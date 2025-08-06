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
        if(p.size()>s.size()) return vector<int>{};
        size_t l_p =0,w=p.size();
        vector<int> res;
        vector<int> s_count(26,0);
        vector<int> p_count(26,0);
        for(auto c:p)
        {
            p_count[c-'a'] = p_count[c-'a'] + 1;
        }
        for(size_t i=0;i<w;i++)
        {
            s_count[s[i]-'a'] += 1; 
        }
        if(is_vec_same(p_count,s_count))
        {
            res.push_back(0);
        }
        for(l_p=1;l_p+w-1<s.size();l_p++)
        {
            size_t r_p = l_p + w - 1;
           s_count[s[l_p-1]-'a'] -= 1;
           s_count[s[r_p]-'a'] += 1;
           if(is_vec_same(s_count,p_count))
           {
            res.push_back(l_p);
           }
        }
        return res;
    }
   
    bool is_vec_same(vector<int>& a,vector<int>& b)
    {
        bool flag = true;
        for(size_t i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string input("abab");
    string p("ab");
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

