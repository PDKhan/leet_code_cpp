class Solution {
public:
    static bool cmp(int& a, int& b){
        return a > b;
    }
    int hIndex(vector<int>& citations) {
        int result;
        sort(citations.begin(), citations.end(), cmp);

        for(int i = 0; i < citations.size(); i++){
            if(citations[i] <= i){
                result = i;
                break;
            }
        }

        return result;
    }
};