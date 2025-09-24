class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> check;

        while(1){
            int sum = 0;
            while(n){
                int num = n % 10;
                sum += num * num;
                n /= 10;
            }
            n = sum;
            if(n == 1)
                break;
            if(check.count(n))
                return false;
            check.insert(n);
        }

        return true;
    }
};
