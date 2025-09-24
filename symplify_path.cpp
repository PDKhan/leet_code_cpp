class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        int len = path.length();
        int start = 0;

        while(start < len){
            while(start < len && path[start] == '/')
                start++;
            
            if(start >= len)
                break;

            int end = start;

            while(end < len && path[end] != '/')
                end++;

            string sub = path.substr(start, end - start);

            if(sub == ".."){
                if(!tokens.empty())
                    tokens.pop_back();
            }else if(sub != ".")
                tokens.push_back(sub);

            if(end >= len)
                break;

            start = end;
        }

        string result;

        if(tokens.empty())
            return "/";

        for(string str : tokens){
            result += "/" + str;
        }

        return result;        
    }
};
