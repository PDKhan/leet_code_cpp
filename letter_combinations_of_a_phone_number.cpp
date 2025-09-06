class Solution {
    const vector<string> letter = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    void dfs(int curr, string& digits, string& buf, vector<string>& result){
        if(curr == digits.length()){
            result.push_back(buf);
            return;
        }

        int idx = digits[curr] - '0';

        for(char ch : letter[idx]){
            buf.push_back(ch);
            dfs(curr + 1, digits, buf, result);
            buf.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};

        vector<string> result;
        string buf;

        dfs(0, digits, buf, result);

        return result;
    }
};
