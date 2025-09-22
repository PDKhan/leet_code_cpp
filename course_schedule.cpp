class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++){
            int pre = prerequisites[i][1];
            int course = prerequisites[i][0];

            graph[pre].push_back(course);
            indegree[course]++;            
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        int visited = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited++;

            for(int next : graph[curr]){
                if(--indegree[next] == 0)
                    q.push(next);
            }
        }

        return numCourses == visited;
    }
};