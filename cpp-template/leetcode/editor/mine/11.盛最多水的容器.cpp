/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=30201
 *
 * [11] 盛最多水的容器
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size()==2) return 1*min(height[0],height[1]);
        size_t l_p = 0, r_p = height.size()-1;
        int max_area = min(height[l_p],height[r_p])*(r_p-l_p);
        while(l_p<r_p)
        {
            if(height[l_p]<=height[r_p])
            {
                 l_p++;
            }
            else{
                r_p--;
            }
            int area = min(height[l_p],height[r_p])*(r_p-l_p);
            max_area = max(max_area,area);
        }
        return max_area;
        // vector<int> dp(height.size(),0);
        // dp[1] = 1*min(height[0],height[1]);
        // for(size_t i=2;i<height.size();i++)
        // {
        //     for(size_t j = 0; j<i;j++)
        //     {
        //         int area = min(height[i],height[j])*(i-j);
        //         dp[i] = max(dp[i],area);
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({1,8,6,2,5,4,8,3,7});
    int res = solution.maxArea(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

