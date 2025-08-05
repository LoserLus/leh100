/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30201
 *
 * [35] 搜索插入位置
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
    int searchInsert(vector<int>& nums, int target) {
        int l_p = 0;
        int r_p = nums.size()-1;
        while(l_p<=r_p)
        {
            int m_p = (l_p+r_p)/2;
            if (nums[m_p]==target)
                return m_p;
            else if (nums[m_p]<target)
            {
                l_p = m_p + 1; 
            }
            else if (nums[m_p]>target)
            {
                r_p = m_p -1;
            }
        }
        return l_p;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */

