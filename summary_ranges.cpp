class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> result;

        if(len == 0)
            return result;

        int start = 0;

        for(int i = 1; i < len; i++){
            if(nums[i] != nums[i - 1] + 1){
                if(start == i - 1){
                    result.push_back(to_string(nums[start]));
                }else{
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
                }

                start = i;
            }
        }

        if(start == len - 1){
            result.push_back(to_string(nums[start]));
        }else{
            result.push_back(to_string(nums[start]) + "->" + to_string(nums[len - 1]));
        }

        return result;
    }
};