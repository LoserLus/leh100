/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30203
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return intervals;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>&b){return a[0]<b[0];});
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            int l = intervals[i][0];
            auto& tmp = res.back();
            int r = tmp[1];
            if(r>=l){tmp[1]=max(tmp[1],intervals[i][1]);}
            else res.push_back(intervals[i]);
        }
        return res;

    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<vector<int>> input = {{1,3},{2,6},{8,10},{6,10},{9,9}};
    vector<vector<int>> res = solution.merge(input);
    print_vec_2d<int>(res);
}



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,7],[1,4]]\n
// @lcpr case=end

 */

