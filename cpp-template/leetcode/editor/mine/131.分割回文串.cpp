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
        if(s.size()==0) return vector<vector<string>>{};
        if(s.size()==1) return vector<vector<string>> {vector<string> {s}};
        createCheckMap(s);
        vector<string> vec;
        func(s,0,vec);
        return res;
        
    }
    void func(string& s, int start,vector<string>& vec)
    {
        if(start>=s.size())
        {
            res.push_back(vec);
            return;
        }
        for(int i = start;i<s.size();i++)
        {
            
            if(checkMap[start][i]==1)
            {
                string tmp = s.substr(start,i-start+1);
                vec.push_back(tmp);
                func(s,i+1,vec);
                vec.pop_back();
            }
        }
    }
    void createCheckMap(string& s)
    {
      for(int i = 0;i<s.size();i++)
      {
        checkMap.push_back(vector<char>(s.size(),0));
      }
      for(int i=s.size()-1;i>=0;i--)
      {
        for(int j = i;j<s.size();j++)
        {
             if(s[i] == s[j])
            {
                if(j-i<=1)
                {
                    checkMap[i][j] = 1;
                }
                else if(checkMap[i+1][j-1]==1)
                {
                    checkMap[i][j] = 1;
                }
            }
        }
      }
        
    }
    // vector<vector<string>> res;
    // vector<vector<string>> partition(string s) {
    //     if(s.size()==0) return vector<vector<string>>{};
    //     if(s.size()==1) return vector<vector<string>> {vector<string> {s}};
    //     vector<string> vec;
    //     func(s,0,vec);
    //     return res;
        
    // }
    // void func(string& s, int start,vector<string>& vec)
    // {
    //     if(start>=s.size())
    //     {
    //         res.push_back(vec);
    //         return;
    //     }
    //     for(int i = start;i<s.size();i++)
    //     {
    //         string tmp = s.substr(start,i-start+1);
    //         if(check(tmp))
    //         {
    //             vec.push_back(tmp);
    //             func(s,i+1,vec);
    //             vec.pop_back();
    //         }
    //     }
    // }
    // bool check(string& s)
    // {
    //     if (s.size()==1)
    //     {
    //         return true;
    //     }
    //     size_t i=0,j=s.size()-1;
    //     while(i<j)
    //     {
    //         if(s[i]!=s[j])
    //         {
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
        
    // }
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

