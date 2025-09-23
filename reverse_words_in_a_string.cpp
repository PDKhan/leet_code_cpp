class Solution {
public:
    string reverseWords(string s) {
        string result;
        int start = 0;
        int len = s.length();

        reverse(s.begin(), s.end());

        while(start < len){
            while(start < len && s[start] == ' ')
                start++;
            
            if(start >= len)
                break;

            int end = start + 1;

            while(end < len && s[end] != ' ')
                end++;

            reverse(s.begin() + start, s.begin() + end);
            result.append(s, start, end - start);
            result += " ";
            start = end;
        }

        if(!result.empty())
            result.pop_back();
        return result;
    }
};
