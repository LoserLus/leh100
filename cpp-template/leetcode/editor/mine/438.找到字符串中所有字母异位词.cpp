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
      if(p.size()>s.size()) return vector<int>{};
      vector<int> p_vec(26,0);
      vector<int> s_vec(26,0);
      vector<int> res;
      for(auto& c:p)
      {
        p_vec[c-'a']++;
      }
      int w = p.size();
      for(int i=0;i<w;i++)
      {
        s_vec[s[i]-'a']++;
      }
      if(s_vec==p_vec) res.push_back(0);
      for(int left=1,right=w;right<s.size();right++,left++)
      {
        s_vec[s[right]-'a']++;
        s_vec[s[left-1]-'a']--;
        if(s_vec==p_vec)
        {
            res.push_back(left);
        }
      
      }
      return res;
       
    }
   
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string input("aaaaaaaaaaaaa");
    string p("aaaaaaaaaa");
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

