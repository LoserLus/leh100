/*
 * @lc app=leetcode.cn id=739 lang=cpp
 * @lcpr version=30202
 *
 * [739] 每日温度
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
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		if (temperatures.size() == 1) return vector<int>{0};
        vector<int> res(temperatures.size(),0);
        stack<int> s;
        s.push(0);
		for (size_t i = 1; i < temperatures.size(); i++)
			{
                int s_top = temperatures[s.top()];
				if(temperatures[i]< s_top)
                {
                    s.push(i);
                }
                else if(temperatures[i] == s_top)
                {
                    s.push(i);
                }
                else if(temperatures[i]>s_top)
                {
                    
                    while(!s.empty()&&temperatures[i]>temperatures[s.top()])
                    {
                
                        res[s.top()] = i-s.top();
                        s.pop();
                        
                    }
                    s.push(i);
                }
                
			}
            return res;
	}
	// vector<int> dailyTemperatures(vector<int> &temperatures)
	// {
	// 	if (temperatures.size() == 1) return vector<int>{0};
    //     vector<int> res(temperatures.size(),0);
	// 	for (size_t i = 0; i < temperatures.size(); i++)
	// 		{
	// 			for (size_t j = i+1; j < temperatures.size(); j++)
	// 				{
    //                     if(temperatures[j]>temperatures[i])
    //                     {
    //                         res[i]= (j-i);
    //                         break;
    //                     }
	// 				}
	// 		}
    //         return res;
	// }
};
// @lc code=end

int main()
{
	Solution solution;
	// your test code here
    vector<int> input = {73,74,75,71,69,72,76,73};
    vector<int> res = solution.dailyTemperatures(input);
    print_vec<int>(res);
}

/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */
