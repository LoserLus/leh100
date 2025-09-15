/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30202
 *
 * [994] 腐烂的橘子
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1},};
    int m = 0, n = 0;
    struct Node
    {
        int r;
        int c;
        Node(int _r,int _c):r{_r},c{_c}{};
    };
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        queue<Node> q;
        m = grid.size();
        n = grid[0].size();
        bool flag = true;
        for(size_t i=0;i<m;i++)
        {
            for(size_t j = 0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(Node(i,j));
                }
                else if(grid[i][j]==1)
                {
                    flag = false;
                }
            }
        }
        if(flag == true) return 0;
        int res = -1;
        // int res = 0;
        // bool spread = false;
        while(!q.empty())
        {
            size_t q_size = q.size();
          
            for(size_t i=0;i<q_size;i++)
            {
                Node tmp = q.front();
                q.pop();
                for(auto& dir:dirs)
                {
                    int nr = tmp.r + dir[0];
                    int nc = tmp.c + dir[1];
                    if(nr<0 || nr >= m) continue;
                    if(nc<0 || nc >= n) continue;
                    if(grid[nr][nc]==0||grid[nr][nc]==2) continue;
                    grid[nr][nc]=2;
                    q.push(Node(nr,nc));
                    // spread = true;
                }
               
            }
            // if(spread)
            // {
            //     res ++;
            //     spread = false;
            // }
            res++;
        }
        for(size_t i=0;i<m;i++)
        {
            for(size_t j = 0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    res = -1;
                    // return -1;
                }
            }
        }
        // return res-1;
        // return res == -1? res:res-1;
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    auto board = makeBoard({
        {2,1,1},
        {1,1,0},
        {0,1,1},
        // {0,2}
	});
	print_vec_2d<int>(board);
	auto res = solution.orangesRotting(board);
	cout << res << endl;
    print_vec_2d<int>(board);
}



/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */

