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
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
      if(grid.size()==0) return 0;
    //   if(grid.size()==1&&grid[0].size()==1) return 1;
      int res = 0;
      for(int i=0;i<grid.size();i++)
      {
        for(int j =0;j<grid[0].size();j++)
        {
            if(grid[i][j]=='0') continue;
            res++;
            func(grid,i,j);
        }
      }
      return res;
    }
    void func(vector<vector<char>>& grid,int r, int c)
    {
        if(r<0||r>=grid.size()) return ;
        if(c<0||c>=grid[0].size()) return ;
        if(grid[r][c]=='0') return;
        grid[r][c] = '0';
        for( auto& dir:dirs)
        {
            int nr = dir.first + r;
            int nc = dir.second + c;
            func(grid,nr,nc);
        }
        return ;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    auto board = makeBoard({
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
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

