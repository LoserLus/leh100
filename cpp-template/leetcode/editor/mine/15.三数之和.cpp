/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30201
 *
 * [15] 三数之和
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(size_t i=0;i<nums.size();i++)
        {
            if(nums[i]>0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            size_t l_p = i+1;
            size_t r_p = nums.size()-1;
            while(l_p<r_p){
                int sum = nums[i] + nums[l_p] + nums[r_p];
                if(0==sum){
                    res.push_back(vector<int>{nums[i],nums[l_p],nums[r_p]});
                    while(l_p<r_p && nums[l_p]==nums[l_p+1]) l_p++;
                    while(l_p<r_p && nums[r_p]==nums[r_p-1]) r_p--;
                    l_p++;
                    r_p -- ;
                }
                else if(sum<0) l_p++;
                else r_p -- ;
            }
            
        }
        return res;
        // vector<vector<int>> res;
        // for(size_t i=0;i<nums.size();i++)
        // {
        //     for(size_t j=0;j<nums.size();j++)
        //     {

        //             for(size_t k=0;k<nums.size();k++)
        //             {
        //                 if(i!=j && i!=k && j!=k)
        //                 {
        //                     if(0 == nums[i]+nums[j]+nums[k])
        //                     {
        //                         res.push_back(vector<int> {nums[i],nums[j],nums[k]});
        //                     }
        //                 }
        //             }
        //     }
            
        // }
        // return res;
    }
};
// @lc code=end

int main() {
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

