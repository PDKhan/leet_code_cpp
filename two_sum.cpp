class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            int val = target - nums[i];

            if(map.count(val)){
                result.push_back(map[val]);
                result.push_back(i);
                break;
            }

            map[nums[i]] = i;
        }

        return result;
    }
};
