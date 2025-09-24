class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int result = 0;

        for(int n : s){
            if(s.count(n - 1) == 0){
                int curr = n;
                int len = 1;
                while(s.count(curr + 1)){
                    curr++;
                    len++;
                }

                result = max(result, len);
            }
        }

        return result;
    }
};
