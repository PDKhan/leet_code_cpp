class Solution {
public:
    string minWindow(string s, string t) {
        int t_map[128] = {0};
        int need = 0;

        for(char ch : t){
            t_map[ch]++;
            need++;
        }
        
        int min_start = -1;
        int min_len = -1;

        int formed = 0;
        int start = 0;
        for(int i = 0; i < s.length(); i++){
            t_map[s[i]]--;
            if(t_map[s[i]] >= 0)
                formed++;
            
            while(need == formed){
                int len = i - start + 1;
                if(min_start == -1 || min_len > len){
                    min_start = start;
                    min_len = len;
                }

                t_map[s[start]]++;
                if(t_map[s[start]] > 0)
                    formed--;
                start++;
            }
        }

        if(min_start == -1)
            return "";
        else
            return s.substr(min_start, min_len);
    }
};
