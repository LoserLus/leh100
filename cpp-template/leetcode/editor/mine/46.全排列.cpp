/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30202
 *
 * [46] 全排列
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
   
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()<=1) return vector<vector<int>> {nums};
        vector<vector<int>> res;
        vector<int> vec;
        func(res,nums,vec,0);
        return res;

    }
   void func(vector<vector<int>>& res,vector<int>& nums,vector<int>& vec,int depth)
   {
        if(depth==nums.size())
        {
            res.push_back(vec);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==-11) continue;
            vec.push_back(nums[i]);
            int tmp = nums[i];
            nums[i]=-11;
            func(res,nums,vec,depth+1);
            nums[i] = tmp;
            vec.pop_back();
        }
   }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({1,2,3});
    vector<vector<int>> res = solution.permute(input);
    print_vec_2d(res);
}



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

