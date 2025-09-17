/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30202
 *
 * [131] 分割回文串
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
vector<vector<string>> res;
vector<vector<char>> checkMap;
    vector<vector<string>> partition(string s) {
       if(s.size()<=1) return vector<vector<string>>{{s}};
       vector<vector<string>> res;
       vector<string> vec;
        func(res,vec,s,0);
        return res;
        
    }
   
   void func(vector<vector<string>>& res,vector<string>& vec,string& s,int depth)
   {
        if(depth==s.size())
        {
            res.push_back(vec);
            return ;
        }

        for(int i=depth;i<s.size();i++)
        {
            string tmp = s.substr(depth,i-depth+1);
            if(!check(tmp)) continue;
            vec.push_back(tmp);
            func(res,vec,s,i+1);
            vec.pop_back();
        }
   }
  bool check(string& s)
  {
    if(s.size()<=1) return true;
    int left=0;
    int right = s.size()-1;
    while(left<right)
    {
        if(s[right]!=s[left]) return false;
        right--;
        left++;
    }
    return true;
  }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string input = "aab";
    vector<vector<string>> res = solution.partition(input);
    print_vec_2d<string>(res);
}



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

