/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30201
 *
 * [283] 移动零
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      
        int l_p = 0,r_p=0;
        int n = nums.size();
        while(r_p<n)
        {
            if(nums[r_p]!=0)
            {
                nums[l_p] = nums[r_p];

                l_p++;
            }
            r_p++;
            
        }
        while(l_p<n)
        {
            nums[l_p]=0;
            l_p++;
        }
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({0,1,0,3,12});
    solution.moveZeroes(input);
    for(int i = 0;i<input.size();i++)
        cout<<input[i]<<";";
    cout<<endl;
}



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

