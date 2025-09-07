class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int dic[26] = {0};

        for(char ch : magazine){
            dic[ch - 'a']++;
        }

        for(char ch : ransomNote){
            if(dic[ch - 'a'] == 0)
                return false;
            dic[ch - 'a']--;
        }

        return true;
    }
};
