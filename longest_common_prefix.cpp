class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";

        string result;

        for(int i = 0; i < strs[0].length(); i++){
            char ch = strs[0][i];

            for(int j = 1; j < strs.size(); j++){
                if(i >= strs[j].length() || ch != strs[j][i])
                    return result;
            }

            result.push_back(ch);
        }

        return result;
    }
};
