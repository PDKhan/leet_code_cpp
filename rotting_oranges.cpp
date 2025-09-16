class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0)
            return 0;

        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};
        int min = 0;
        
        while(!q.empty()){
            int len = q.size();

            if(fresh == 0)
                return min;

            for(int i = 0; i < len; i++){
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();

                for(int j = 0; j < 4; j++){
                    int nr = cr + dr[j];
                    int nc = cc + dc[j];

                    if(nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                }
            } 
            min++;
        }

        return -1;
    }
};
