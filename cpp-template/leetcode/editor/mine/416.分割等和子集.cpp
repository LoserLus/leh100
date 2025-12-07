/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30203
 *
 * [416] 分割等和子集
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return false;
        vector<int> vec;
        map<vector<int>, bool> mem;
        int sum = vec_sum(nums);
        bool res = func(nums, sum, vec, mem);
        return res;
    }
    bool func(vector<int> &nums, int sum, vector<int> &vec, map<vector<int>, bool> &mem)
    {
        vector<int> vec_b(vec);
        sort(vec_b.begin(),vec_b.end());
        if (mem.count(vec_b))
            return mem[vec_b];
        if (2 * vec_sum(vec) == sum)
            return true;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -1)
                continue;
            int tmp = nums[i];
            vec.push_back(nums[i]);
            vector<int> vec_c(vec);
            sort(vec_c.begin(),vec_c.end());
            nums[i] = -1;
            if (func(nums, sum, vec, mem) == false)
            {
                
                
                mem[vec_c] = false;
                vec.pop_back();
                nums[i] = tmp;
            }
            else
            {
                mem[vec_c] = true;
                return true;
            }
        }

        return false;
    }
    int vec_sum(vector<int> &vec)
    {
        int sum = 0;
        for (auto v : vec)
        {
            sum += v;
        }
        return sum;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
    vector<int> input = {1, 2, 3, 5};
    bool res = solution.canPartition(input);
    cout << res << endl;
}

/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */
