class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for(int i = 0; i < 32; i++){
            int bit_sum = 0;

            for(int j = 0; j < nums.size(); j++)
                bit_sum += ((nums[j] >> i) & 1);

            if(bit_sum % 3)
                result |= 1U << i;
        }

        return result;
    }
};