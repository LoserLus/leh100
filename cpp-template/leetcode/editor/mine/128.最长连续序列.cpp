/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30202
 *
 * [128] 最长连续序列
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"
using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return nums.size();
        unordered_set<int> set(nums.begin(),nums.end());
        int max_len = 0;
        for(auto num :set)
        {
            if(set.find(num-1)!=set.end())
            {
                continue;
            }
            else{
                int y = 1;
                while(set.find(num+y)!=set.end()) y++;
                max_len = max_len>y ? max_len:y;
            }
        }
        return max_len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({1,0,1,2});
    int res = solution.longestConsecutive(input);
    cout<<res<<endl;
}



/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,2]\n
// @lcpr case=end

 */

