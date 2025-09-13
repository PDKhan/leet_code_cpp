class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int end = n * n;

        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({1, 0});
        visited.insert(1);

        while(!q.empty()){
            int curr = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(curr == end)
                return dist;
            
            for(int dice = 1; dice <= 6; dice++){
                int next = curr + dice;

                if(next > end)
                    break;

                int r = (n - 1) - ((next - 1) / n);
                int c;

                if((n - 1 - r) % 2)
                    c = (n - 1) - (next - 1) % n;
                else
                    c = (next - 1) % n;
                
                if(board[r][c] != -1)
                    next = board[r][c];
                
                if(visited.count(next))
                    continue;
                q.push({next, dist + 1});
                visited.insert(next);
            }
            
        }

        return -1;
    }
};
