/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30202
 *
 * [79] 单词搜索
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    int m,n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
	bool exist(vector<vector<char>> &board, string word)
	{
		if (word.size() == 0 || board.size() == 0) return false;
		vector<char> vec;

		bool flag = false;
        m = board.size();
        n = board[0].size();
        // vector<vector<int>> visited(m, vector<int>(n, 0));
		for (size_t i = 0; i < m; i++)
			{
				for (size_t j = 0; j <n; j++)
					{
						// vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
						flag = func(board, word, i, j, 0);
                        // flag = func(board, word, visited, i, j, 0);
						if (flag) return true;
					}
			}

		return false;
	}
    bool func(vector<vector<char>> &board, string &word, int row, int col, int depth)
	// bool func(vector<vector<char>> &board, string &word, vector<vector<int>> &visited, int row, int col, int depth)
	{
        
		if (board[row][col] != word[depth]) return false;
        if(depth==word.size()-1) return true;

        char tmp = board[row][col];
        board[row][col] = '#';
		// visited[row][col] = 1;
		for(auto& dir:dirs)
        {
            int nr = row + dir[0];
            int nc = col + dir[1];
            if(nr<0||nr>=m) continue;
            if(nc<0||nc>=n) continue;
            if(board[nr][nc]=='#') continue;
            // if(visited[nr][nc]==1) continue;
            if(func(board, word, nr, nc, depth + 1))
            // if(func(board, word, visited, nr, nc, depth + 1))
            {
                return true;
            }
        }
        board[row][col] = tmp;
        // visited[row][col] = 0;
        return false;
	}
};
// @lc code=end

int main()
{
	Solution solution;
	// your test code here
	// [["C","A","A"],["A","A","A"],["B","C","D"]]
	// "AAB"
	string word = "AAAAAAAAAAAAABB";
	auto board = makeBoard({
		// {'a'}
		// {'a','b'},
		// {'c','d'},
		// {'A', 'B', 'C', 'E'},
		// {'S', 'F', 'E', 'S'},
		// {'A', 'D', 'E', 'E'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','B'},
        {'A','A','A','A','B','A'}
		// {'C','A','A'},
		// {'A','A','A'},
		// {'B','C','D'}
		// {'A','B','C','E'},
		// {'S','F','C','S'},
		// {'A','D','E','E'}
	});
	print_vec_2d<char>(board);
	bool res = solution.exist(board, word);
	cout << res << endl;
}

/*
// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCB"\n
// @lcpr case=end

 */
