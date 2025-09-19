class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int start_color = image[sr][sc];

        if(start_color == color)
            return image;

        queue<pair<int, int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});

        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n || image[nr][nc] != start_color)
                    continue;
                
                image[nr][nc] = color;
                q.push({nr, nc});
            }
        }

        return image;
    }
};
