class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[r].size() || grid[r][c] == '0')
            return;
        
        grid[r][c] = '0';
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }
};
