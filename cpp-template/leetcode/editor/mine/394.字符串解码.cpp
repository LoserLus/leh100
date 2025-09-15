/*
 * @lc app=leetcode.cn id=394 lang=cpp
 * @lcpr version=30202
 *
 * [394] 字符串解码
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        if(s.size()==1) return s;
        stack<int> op_stack;
        stack<char> char_stack;
        vector<char> vec;
        int repeat = 0;
        for(size_t index = 0;index<s.size();index++)
        {
            char c = s[index];
            if('0'<=c && c<= '9')
            {
                repeat = repeat*10 + c-'0';
                continue;
            }
            if(c=='[')
            {
                op_stack.push(repeat);
                repeat = 0;
                char_stack.push(c);
                while(s[index]!=']')
                {
                    char_stack.push(s[index]);
                    index++;
                }
                c = char_stack.top();
                while(c!='[')
                {
                    vec.push_back(c);
                    char_stack.pop();
                    c = char_stack.top();
                }
                char_stack.pop();
                int cnt = op_stack.top();
                op_stack.pop();
                while(cnt--)
                {
                    for(int i = vec.size()-1;i>=0;i--)
                    {
                        char_stack.push(vec.back());
                        vec.pop_back();
                    }
                }

            }

        }
        return string("");
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    string input = "3[a]2[bc]";
    string res = solution.decodeString(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// "3[a]2[bc]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

// @lcpr case=start
// "abc3[cd]xyz"\n
// @lcpr case=end

 */

