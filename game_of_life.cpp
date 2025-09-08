class Solution {
public:
    int check(int r, int c, vector<vector<int>>& board){
        int cnt = 0;

        if(r > 0)
            cnt += (board[r - 1][c] & 1);

        if(r + 1 < board.size())
            cnt += (board[r + 1][c] & 1);

        if(c > 0)
            cnt += (board[r][c - 1] & 1);

        if(c + 1 < board[r].size())
            cnt += (board[r][c + 1] & 1);

        if(r > 0 && c > 0)
            cnt += (board[r - 1][c - 1] & 1);

        if(r > 0 && c + 1 < board[r].size())
            cnt += (board[r - 1][c + 1] & 1);

        if(r + 1 < board.size() && c > 0)
            cnt += (board[r + 1][c - 1] & 1);

        if(r + 1 < board.size() && c + 1 < board[r].size())
            cnt += (board[r + 1][c + 1] & 1);
        
        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                int cnt = check(i, j, board);
                if((board[i][j] & 1) == 1){
                    if(cnt == 2 || cnt == 3)
                        board[i][j] = 3;
                }else{
                    if(cnt == 3)
                        board[i][j] = 2;
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                board[i][j] >>= 1;
            }
        }
    }
};
