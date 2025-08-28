/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30202
 *
 * [22] 括号生成
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
	vector<string> res;
	string str = "()";
	vector<string> generateParenthesis(int n)
	{
		if (n == 0) return vector<string>{};
		if (n == 1) return vector<string>{"()"};
		vector<char> vec;
		func(n, 0, vec);
		return res;
	}
	void func(int n, int depth, vector<char> &vec)
	{
		if (depth == 2 * n)
			{
                if(check(vec,n))
			    	res.push_back(string(vec.begin(), vec.end()));
				return;
			}
		for (auto c : str)
			{
				vec.push_back(c);
				func(n, depth + 1, vec);
				vec.pop_back();
			}
	}
	bool check(vector<char> &vec, int n)
	{
		int balance = 0;
		for (char c : vec)
			{
				if (c == '(')
					{
						balance++;
					}
				else if (c == ')')
					{
						balance--;
						if (balance < 0) return false; // 右括号多了
					}
				else
					{
						return false; // 非法字符
					}
			}
		return balance == 0;
	}
	// vector<string> res;
	// vector<string> generateParenthesis(int n) {
	//     if(n==0) return vector<string> {};
	//     if(n==1) return vector<string> {"()"};
	//     vector<char> vec;
	//     func(0,0,n,vec);
	//     return res;

	// }
	// void func(int left,int right,int n, vector<char>& vec)
	// {
	//     if(left==n && right == n)
	//     {
	//         res.push_back(string(vec.begin(),vec.end()));
	//         return;
	//     }
	//     if(left < n)
	//     {
	//         vec.push_back('(');
	//         func(left+1,right,n,vec);
	//         vec.pop_back();
	//     }
	//     // 这里不能用left>=right，如果相等则此时括号已经闭合，再加)不合法
	//     //也就是说放入右括号之前必须满足左括号的数量大于右括号的数量，放入后可以相等
	//     if(right<n && left > right)
	//     {
	//         vec.push_back(')');
	//         func(left,right+1,n,vec);
	//         vec.pop_back();
	//     }
	// }
};
// @lc code=end

int main()
{
	Solution solution;
	// your test code here
	int input = 3;
	vector<string> res = solution.generateParenthesis(input);
	print_vec<string>(res);
}

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
