class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int start = 0;
        int result = 0;

        for(int i = 0; i < s.length(); i++){
            if(map[s[i]] > start)
                start = map[s[i]];
            
            int len = i - start + 1;
            result = max(result, len);
            map[s[i]] = i + 1;
        }

        return result;
    }
};
