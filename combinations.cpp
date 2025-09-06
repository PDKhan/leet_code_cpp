class Solution {
public:
    void dfs(int start, int n, int pos, int k, vector<int>& buf, vector<vector<int>>& result){
        if(pos == k){
            result.push_back(buf);
            return;
        }

        for(int i = start; i <= n; i++){
            buf.push_back(i);
            dfs(i + 1, n, pos + 1, k, buf, result);
            buf.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> buf;

        dfs(1, n, 0, k, buf, result);

        return result;
    }
};
