/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=30202
 *
 * [49] 字母异位词分组
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <unordered_map>
#include <algorithm>
#include "../common/utils.cpp"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(auto s:strs)
        {
            string key = s;
            sort(key.begin(),key.end());
            if(map.find(key)!=map.end())
            {
                map[key].push_back(s);
            }
            else
            {
                map[key] = vector<string>{s};
            }

        }
        vector<vector<string>> res;
        for(auto it = map.begin();it!=map.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<string> input({"eat", "tea", "tan", "ate", "nat", "bat"});
    vector<vector<string>> res = solution.groupAnagrams(input);
    print_vec_2d<string>(res);
}



/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */

