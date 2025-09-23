class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int start = 0;
        int len = nums.size();
        int result = INT_MAX;

        for(int i = 0; i < len; i++){
            sum += nums[i];

            while(start <= i && sum >= target){
                result = min(result, i - start + 1);
                sum -= nums[start];
                start++;
            }
        }

        return result == INT_MAX ? 0 : result;;
    }
};
