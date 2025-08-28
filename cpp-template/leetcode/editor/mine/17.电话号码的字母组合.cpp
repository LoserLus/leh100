/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30202
 *
 * [17] 电话号码的字母组合
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:

    unordered_map<char,string> hashmap={
        {'2',"abc"},
        {'3',"def"},
        {'4',"hgi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return vector<string> {};
        if(digits.size()==1)
        {
            string s = hashmap[digits[0]];
            
            for(size_t i =0;i<s.size();i++)
            {
                res.push_back(string(1,s[i]));
            }
            return res;
        }
        vector<char> vec;
        func(digits,vec,0);
        return res;
    }
    void func(string& digits,vector<char>& vec,size_t depth)
    {
        if(depth == digits.size())
        {
            string s(vec.begin(),vec.end());
            res.push_back(s);
            return;
        }
        string str = hashmap[digits[depth]];
        for(size_t i=0;i<str.size();i++)
        {
            vec.push_back(str[i]);
            func(digits,vec,depth+1);
            vec.pop_back();
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string input = "2";
    vector<string> res = solution.letterCombinations(input);
    print_vec<string>(res);
}



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

