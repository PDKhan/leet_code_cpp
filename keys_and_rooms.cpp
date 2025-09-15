class Solution {
public:
    void dfs(int curr, vector<vector<int>>& rooms, unordered_set<int>& visited){
        if(visited.count(curr))
            return;
        
        visited.insert(curr);
        for(int i = 0; i < rooms[curr].size(); i++){
            dfs(rooms[curr][i], rooms, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;

        dfs(0, rooms, visited);

        return n == visited.size();
    }
};
