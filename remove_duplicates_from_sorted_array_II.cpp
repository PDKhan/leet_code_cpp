class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int cnt = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[idx] == nums[i]){
                cnt++;
                if(cnt < 3)
                    idx++;
            }else{
                idx++;
                cnt = 1;
            }
            nums[idx] = nums[i];
        }

        return idx + 1;
    }
};
