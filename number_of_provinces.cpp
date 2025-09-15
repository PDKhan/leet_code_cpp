class Solution {
public:
    void dfs(int curr, vector<vector<int>>& isConnected, vector<bool>& visited){
        if(visited[curr])
            return;

        visited[curr] = true;

        for(int i = 0; i < isConnected[curr].size(); i++){
            if(isConnected[curr][i] == 1)
                dfs(i, isConnected, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, isConnected, visited);
                cnt++;
            }
        }

        return cnt;
    }
};
