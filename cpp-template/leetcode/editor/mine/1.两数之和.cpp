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
// #include "../common/ListNode.cpp"
// #include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
     vector<int> twoSum(vector<int>& nums, int target) {
        vector<Node> vec;
        for (int i = 0; i < nums.size(); i++)
        {
            vec.push_back(Node{nums[i],i});
        }
        auto cmp = [](Node&n1,Node&n2)->bool {return n1.num<n2.num;};
        sort(vec.begin(), vec.end(),cmp);
        for (int i = 0; i < vec.size(); i++) {
            int min = vec[i].num;
            int find_value = target - min;
            if (find_value > vec.back().num)
                continue;
          
            int index = binary_sarch(vec, i, find_value);
            if (index != -1) {
                // vector<int> r= {vec[i].pos, vec[index].pos};
                // return r;
                return vector<int> {vec[i].pos, vec[index].pos};
            }
        }
        return vector<int>{-1,-1};
    }
    struct Node{
            int num;
            int pos;
        };
    int binary_sarch(vector<Node>& nums, int start, int value) {
        int index = -1;
        if (nums.back().num < value)
            return index;
        int l_index = start+1;
        int r_index = nums.size() - 1;
        
        while(l_index<=r_index)
        {
            int m_index = (l_index + r_index) / 2;
            if(nums[m_index].num==value) return m_index;
            else if (nums[m_index].num < value)
            {
                l_index = m_index + 1;
            }
            else if(nums[m_index].num>value)
            {
                r_index = m_index -1;
            }
        }
        return index;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({3,3});
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

