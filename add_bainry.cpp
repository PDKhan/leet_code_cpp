class Solution {
public:
    string addBinary(string a, string b) {
        int a_idx = a.length() - 1;
        int b_idx = b.length() - 1;
        int carry = 0;
        string result;

        while(a_idx >= 0 || b_idx >= 0 || carry){
            if(a_idx >= 0)
                carry += a[a_idx--] - '0';
            
            if(b_idx >= 0)
                carry += b[b_idx--] - '0';
            
            result += to_string(carry % 2);
            carry /= 2;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
