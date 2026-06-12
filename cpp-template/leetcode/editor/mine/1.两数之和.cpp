/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30201
 *
 * [1] 两数之和
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
// #include "../common/ListNode.cpp"
// #include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
     vector<int> twoSum(vector<int>& nums, int target)
     {
        unordered_map<int,int> num_map;
        for(int i=0;i<nums.size();i++)
        {
            auto it = num_map.find(target-nums[i]);
            if(it!=num_map.end())
            {
                return vector<int>{i,it->second};
            }
            num_map[nums[i]]=i;
        }
        return vector<int>{-1,-1};
     }
  
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({2,7,11,15});
    vector<int> res = solution.twoSum(input,9);
    cout<<res[0]<<";"<<res[1]<<endl;

}



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

