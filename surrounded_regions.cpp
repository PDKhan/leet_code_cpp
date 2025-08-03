class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[r].size() || board[r][c] != 'O')
            return;
        
        board[r][c] = 'T';

        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'O' && (i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1))
                    dfs(i, j, board);
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};