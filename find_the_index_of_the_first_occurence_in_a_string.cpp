class Solution {
public:
    int strStr(string haystack, string needle) {
        int n_len = needle.length();
        int h_len = haystack.length();
        if(n_len == 0)
            return 0;
        if(n_len > h_len)
            return -1;

        for(int i = 0; i + n_len <= h_len; i++){
            if(haystack[i] == needle[0]){
                int j;
                for(j = 1; j < n_len; j++){
                    if(haystack[i + j] != needle[j])
                        break;
                }

                if(j == needle.size())
                    return i;
            }
        }

        return -1;
    }
};
