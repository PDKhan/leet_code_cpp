class Solution {
public:
    bool dfs(int curr, int numCourses, vector<vector<int>>& graph, vector<int>& visited){
        if(visited[curr] == 1)
            return false;
        
        if(visited[curr] == 2)
            return true;
        
        visited[curr] = 1;

        for(int i = 0; i <graph[curr].size(); i++){
            if(!dfs(graph[curr][i], numCourses, graph, visited))
                return false;
        }

        visited[curr] = 2;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];

            graph[pre].push_back(course);
        }

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i, numCourses, graph, visited))
                return false;
        }

        return true;
    }
};