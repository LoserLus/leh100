/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30202
 *
 * [20] 有效的括号
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
class Solution
{
public:
	bool isValid(string s)
	{
		if (s.size() <= 1) return false;
		stack<char> op_stack;
		op_stack.push(s[0]);
		char c;
		for (size_t i = 1; i < s.size(); i++)
			{
				if (!op_stack.empty())
					{
						c = op_stack.top();
						if ((c == '(' && s[i] == ')') || (c == '{' && s[i] == '}') || (c == '[' && s[i] == ']'))
							{
								op_stack.pop();
							}
						else
							{
								op_stack.push(s[i]);
							}
					}
				else
					{
						op_stack.push(s[i]);
					}
			}
		if (op_stack.empty()) return true;
		return false;
	}
};
// @lc code=end

int main()
{
	Solution solution;
	// your test code here
	string input = "()[]{}";
	bool res = solution.isValid(input);
	cout << res << endl;
}

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */
