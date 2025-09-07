class Solution {
public:
    void dfs(int l, int r, string& buf, vector<string>& result){
        if(l == 0 && r == 0){
            result.push_back(buf);
            return;
        }

        if(r == 0 || l > r)
            return;

        if(l > 0){
            buf.push_back('(');
            dfs(l - 1, r, buf, result);
            buf.pop_back();
        }
        if(r > 0){
            buf.push_back(')');
            dfs(l, r - 1, buf, result);
            buf.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string buf;

        dfs(n, n, buf, result);

        return result;
    }
};
