/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30203
 *
 * [53] 最大子数组和
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       if(nums.size()==0) return 0;
       if(nums.size()==1) return nums[0];
    //    vector<int> dp(nums);
        auto& dp = nums;
       for (int i = 1; i < dp.size(); i++)
       {
            if(dp[i-1]>0) dp[i]+=dp[i-1];
       }
       return *max_element(dp.begin(),dp.end());
       
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    int res = solution.maxSubArray(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

