class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int sr = entrance[0];
        int sc = entrance[1];

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        q.push({{sr, sc}, 0});
        visited[sr][sc] = 1;

        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        while(!q.empty()){
            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int d = q.front().second;
            q.pop();

            if((cr != sr || cc != sc) && (cr == 0 || cr == m - 1 || cc == 0 || cc == n - 1))
                return d;
            
            for(int i = 0; i < 4; i++){
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n || maze[nr][nc] == '+' || visited[nr][nc])
                    continue;
                
                q.push({{nr, nc}, d + 1});
                visited[nr][nc] = 1;
            }
        }

        return -1;
    }
};
