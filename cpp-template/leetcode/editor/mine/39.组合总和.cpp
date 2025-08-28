/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30202
 *
 * [39] 组合总和
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
     vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==1 && candidates[0]>target) return vector<vector<int>>{};
        vector<int> vec;
        func(candidates,vec,target,0);
        return res;
    }
    void func(vector<int>& candidates,vector<int>& vec, int target,size_t start)
    {
        if(vec_sum(vec)>target) return;
        if(vec_sum(vec)==target)
        {
            res.push_back(vec);
            return;
        }
        for(size_t i=start;i<candidates.size();i++)
        {
            vec.push_back(candidates[i]);
            func(candidates,vec,target,i);
            vec.pop_back();
        }
    }
    int vec_sum(vector<int>& vec)
    {
        int sum = 0;
        for(auto n:vec)
        {
            sum+=n;
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> input({2,3,6,7});
	int k = 7;
	vector<vector<int>> res = solution.combinationSum(input, k);
    print_vec_2d<int>(res);
}



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

