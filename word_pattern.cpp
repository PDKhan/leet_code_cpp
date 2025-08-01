class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c_map;
        unordered_map<string, char> s_map;
        int start = 0;

        for(int i = 0; i < pattern.length(); i++){
            if(start > s.length())
                return false;

            int pos = s.find(' ', start);

            if(pos == string::npos)
                pos = s.length();

            string word = s.substr(start, pos - start);
            start = pos + 1;

            char c = pattern[i];

            if(c_map.count(c) && c_map[c] != word)
                return false;
            
            if(s_map.count(word) && s_map[word] != c)
                return false;
            
            c_map[c] = word;
            s_map[word] = c;
        }

        return start > s.length();
    }
};
