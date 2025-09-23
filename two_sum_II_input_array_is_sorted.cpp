class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> table;
        vector<int> result;

        for(int i = 0; i < numbers.size(); i++){
            int diff = target - numbers[i];

            if(table.count(diff)){
                result.push_back(table[diff]);
                result.push_back(i + 1);
                return result;
            }

            table[numbers[i]] = i + 1;
        }

        return {};
    }
};
