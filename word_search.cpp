class Solution {
public:
    bool dfs(int r, int c, int pos, vector<vector<char>>& board, string word){
        if(pos == word.length())
            return true;
        if(r < 0 || r >= board.size() || c < 0 || c >= board[r].size() || board[r][c] != word[pos])
            return false;
        
        char org = board[r][c];
        board[r][c] = '0';
        bool ret =  dfs(r - 1, c, pos + 1, board, word) ||
                dfs(r + 1, c, pos + 1, board, word) ||
                dfs(r, c - 1, pos + 1, board, word) ||
                dfs(r, c + 1, pos + 1, board, word);
        
        board[r][c] = org;
        return ret;   
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0]){
                    if(dfs(i, j, 0, board, word) == true)
                        return true;
                }
            }
        }

        return false;
    }
};
