class Solution {
public:
    bool check(int r_start, int r_end, int c_start, int c_end, vector<vector<char>>& board){
        int ar[10] = {0};

        for(int i = r_start; i < r_end; i++){
            for(int j = c_start; j < c_end; j++){
                if(isdigit(board[i][j])){
                    int idx = board[i][j] - '0';

                    ar[idx]++;

                    if(ar[idx] >= 2)
                        return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            if(check(i, i + 1, 0, board[i].size(), board) == false)
                return false;
        }

        for(int j = 0; j < board[0].size(); j++){
            if(check(0, board.size(), j, j + 1, board) == false)
                return false;
        }

        for(int i = 0; i < board.size(); i += 3){
            for(int j = 0; j < board[i].size(); j += 3){
                if(check(i, i + 3, j, j + 3, board) == false)
                    return false;
            }
        }

        return true;
    }
};
