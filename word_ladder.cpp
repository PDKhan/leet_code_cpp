class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord)
            return 0;
        
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if(dict.count(endWord) == 0)
            return 0;

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);

        while(!q.empty()){
            string curr = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(curr == endWord)
                return dist;
            
            for(int i = 0; i < curr.length(); i++){
                char org = curr[i];
                for(int j = 0; j < 26; j++){
                    char c = 'a' + j;
                    if(c == org)
                        continue;
                    curr[i] = c;
                    if(dict.count(curr) && visited.count(curr) == 0){
                        q.push({curr, dist + 1});
                        visited.insert(curr);
                    }
                }

                curr[i] = org;
            }
        }

        return 0;
    }
};
