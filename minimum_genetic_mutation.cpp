class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene)
            return 0;

        queue<pair<string, int>> q;

        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);

        while(!q.empty()){
            string curr = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(curr == endGene){
                return cnt;
            }

            for(string next : bank){
                int diff = 0;
                for(int i = 0; i < next.length(); i++){
                    if(curr[i] != next[i])
                        diff++;
                }

                if(diff == 1 && visited.count(next) == 0){
                    q.push({next, cnt + 1});
                    visited.insert(next);
                }
            }
        }

        return -1;
    }
};
