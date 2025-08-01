class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;

        for(int i = 0; i < strs.size(); i++){
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            map[copy].push_back(strs[i]);
        }

        for(auto pair : map){
            result.push_back(pair.second);
        }

        return result;        
    }
};
