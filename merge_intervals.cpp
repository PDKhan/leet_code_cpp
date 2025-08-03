class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            vector<int>& vt = result.back();

            if(vt[1] >= intervals[i][0]){
                vt[1] = fmax(vt[1], intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
