/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30201
 *
 * [15] 三数之和
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> res;
        unordered_map<int, int> hash_map;
        for (auto num : nums)
        {
            if (hash_map.count(num))
                hash_map[num]++;
            else
                hash_map[num] = 1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int sum = nums[i] + nums[j];
                hash_map[nums[i]]--;
                hash_map[nums[j]]--;
                if (hash_map.count(-sum) && hash_map[-sum] >= 1)
                {
                    vector<int> tmp = {nums[i], nums[j], -sum};
                    sort(tmp.begin(), tmp.end());
                    res.insert(tmp);
                }
                hash_map[nums[i]]++;
                hash_map[nums[j]]++;
            }
        }
        vector<vector<int>> r;
        for (auto &v : res)
        {
            r.push_back(v);
        }
        return r;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
    vector<int> input({0,0,0,0});
    vector<vector<int>> res = solution.threeSum(input);
    print_vec_2d(res);
}

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
