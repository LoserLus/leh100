/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30202
 *
 * [200] 岛屿数量
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
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    int m = 0, n= 0;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for(size_t i =0;i<m;i++)
        {
            for(size_t j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    res++;
                    func(grid,i,j);
                }
            }
        }
        return res;
    }
    void func(vector<vector<char>>& grid,int r,int c)
    {
        if(grid[r][c]=='0') return;
        grid[r][c] = '0';
        for(auto& dir:dirs)
        {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr>=m || nr<0) continue;
            if(nc>=n || nc<0) continue;
            func(grid,nr,nc); 
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    auto board = makeBoard({
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},
	});
	print_vec_2d<char>(board);
	auto res = solution.numIslands(board);
	cout << res << endl;
    print_vec_2d<char>(board);
}



/*
// @lcpr case=start
// [\n['1','1','1','1','0'],\n['1','1','0','1','0'],\n['1','1','0','0','0'],\n['0','0','0','0','0']\n]\n
// @lcpr case=end

// @lcpr case=start
// [\n['1','1','0','0','0'],\n['1','1','0','0','0'],\n['0','0','1','0','0'],\n['0','0','0','1','1']\n]\n
// @lcpr case=end

 */

