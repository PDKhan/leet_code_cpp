class Solution {
public:
    bool dfs(int curr, int numCourses, vector<vector<int>>& graph, vector<int>& visited, vector<int>& result){
        if(visited[curr] == 1)
            return false;
        
        if(visited[curr] == 2)
            return true;
        
        visited[curr] = 1;

        for(int i = 0; i <graph[curr].size(); i++){
            if(!dfs(graph[curr][i], numCourses, graph, visited, result))
                return false;
        }

        result.push_back(curr);

        visited[curr] = 2;

        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> result;

        for(int i = 0; i < prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];

            graph[pre].push_back(course);
        }

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i, numCourses, graph, visited, result))
                return result;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
