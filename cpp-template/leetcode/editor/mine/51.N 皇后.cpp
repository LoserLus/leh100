/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30202
 *
 * [51] N 皇后
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
    vector<vector<string>> res;
    string str;
    vector<vector<string>> solveNQueens(int n) {
        if(n==1) return vector<vector<string>>{{vector<string>{"Q"}}};
        str = string(n,'.');
        vector<string> vec;
        func(n,0,vec);
        return res;
    }
    void func(int n, int depth,vector<string>& vec)
    {
        if(depth == n)
        {
            res.push_back(vec);
            return;
        }
        for(int i =0;i<n;i++)
        {
            if(check(n,depth,i,vec))
            {
                string tmp = str;
                tmp[i] = 'Q';
                vec.push_back(tmp);
                func(n,depth+1,vec);
                vec.pop_back();
            }
        }
    }
    bool check(int n, int row, int col,vector<string>& vec)
    {
        if(vec.size()==0) return true;
        for(int i =0;i< row; i++)
        {
            for(int j =0;j< n;j++)
            {
                if(vec[i][j]=='Q')
                {
                    if(j==col) return false;
                    if(abs(i-row)==abs(j-col)) return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    int n = 1;
    vector<vector<string>> res = solution.solveNQueens(n);
    print_vec_2d<string>(res);
}



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

