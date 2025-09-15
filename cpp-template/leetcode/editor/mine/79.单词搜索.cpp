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
vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
	bool exist(vector<vector<char>> &board, string word)
	{
		if(word.size()==0||board.size()==0) return false;
		bool res = false;
		for(int i=0;i<board.size();i++)
		{
			for(int j=0;j<board[0].size();j++)
			{
				res = func(board,word,i,j,0);
				if(res) return true;

			}
		}
		return false;
	}
  bool func(vector<vector<char>> &board,string& word,int r,int c,int depth)
  {
	if(r<0||r>=board.size()) return false;
	if(c<0||c>=board[0].size()) return false;
	if(board[r][c]=='#') return false;
	if(board[r][c]!=word[depth]) return false;

	if(depth==word.size()-1) return true;
	
	bool res = false;
	char tmp = board[r][c];
	board[r][c] = '#';
	for(auto& dir:dirs)
	{
		int nr = r + dir.first;
		int nc = c + dir.second;
		res |= func(board,word,nr,nc,depth+1);
		
	}
	board[r][c] = tmp;
	return res;

  }
};
// @lc code=end

int main()
{
	Solution solution;
	// your test code here
	// [["C","A","A"],["A","A","A"],["B","C","D"]]
	// "AAB"
	string word = "SEE";
	auto board = makeBoard({
		// {'a'}
		// {'a','b'},
		// {'c','d'},
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'},
        // {'A','A','A','A','A','A'},
        // {'A','A','A','A','A','A'},
        // {'A','A','A','A','A','A'},
        // {'A','A','A','A','A','A'},
        // {'A','A','A','A','A','B'},
        // {'A','A','A','A','B','A'}
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
