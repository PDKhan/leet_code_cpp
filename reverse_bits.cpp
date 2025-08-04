class Solution {
public:
    int reverseBits(int n) {
        int result = 0;

        for(int i = 0; i < 32; i++){
            result <<= 1;
            result |= ((n >> i) & 1);
        }

        return result;
    }
};