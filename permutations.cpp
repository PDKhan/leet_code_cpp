class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& visited, vector<int>& buf, vector<vector<int>>& result){
        if(nums.size() == buf.size()){
            result.push_back(buf);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == 1)
                continue;
            visited[i] = 1;
            buf.push_back(nums[i]);
            dfs(nums, visited, buf, result);
            buf.pop_back();
            visited[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> buf;
        vector<int> visited(nums.size(), 0);

        dfs(nums, visited, buf, result);
        return result;
    }
};
