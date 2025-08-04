class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int product = 1;
        int zero = 0;

        for(int i = 0; i < nums.size(); i++){
            result.push_back(product);
            product *= nums[i];
        }

        product = 1;

        for(int i = nums.size() - 1; i >= 0; i--){
            result[i] = result[i] * product;
            product = product * nums[i];
        }

        return result;
    }
};
