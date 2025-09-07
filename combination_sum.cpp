class Solution {
public:
    void dfs(vector<int>& candidates, int start, int target, vector<int>& buf, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(buf);
            return;
        }
        if(target < 0)
            return;

        for(int i = start; i < candidates.size(); i++){
            buf.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i], buf, result);
            buf.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> buf;

        sort(candidates.begin(), candidates.end());

        dfs(candidates, 0, target, buf, result);
        return result;
    }
};
