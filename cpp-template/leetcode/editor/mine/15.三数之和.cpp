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
       sort(nums.begin(),nums.end());
       vector<vector<int>> res;
       for(int i=0;i<nums.size();i++)
       {
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum>0) right--;
                else if(sum<0) left++;
                else
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    // 判断的顺序不能错，对于left是判断当前left和下一个是否相同，相同再移动
                    while(left<right&&nums[left]==nums[left+1]) left++;
                    // 对于right也是判断是否与下一个相同
                    while(left<right&&nums[right]==nums[right-1]) right--;
                    // 经过循环之后，left需要继续移动一次才能保证去重
                    left++;
                    right--;
                }
            }

       }
       return res;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
    vector<int> input({-1,0,1,2,-1,-4});
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
