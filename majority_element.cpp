class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
        int cnt = 1;

        for(int i = 1; i < nums.size(); i++){
            if(result == nums[i])
                cnt++;
            else
                cnt--;
            
            if(cnt == 0){
                result = nums[i];
                cnt = 1;
            }
        }

        return result;
    }
};