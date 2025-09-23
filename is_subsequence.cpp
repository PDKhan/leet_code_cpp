class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_idx = 0;
        int s_len = s.length();

        for(char ch : t){
            if(s[s_idx] == ch)
                s_idx++;
        }

        return s_idx == s_len;
    }
};
