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
        int res = INT32_MIN;
        int min_presum = 0;
        int presum = 0;
        for(int i=0;i<nums.size();i++)
        {
            presum +=nums[i];
            res = max(res,presum-min_presum);
            min_presum = min(presum,min_presum);
        }
        return res;
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

