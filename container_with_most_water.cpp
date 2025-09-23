class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;

        while(left < right){
            int h;
            int len = right - left;

            if(height[left] < height[right]){
                h = height[left];
                left++;
            }else{
                h = height[right];
                right--;
            }
            
            result = max(result, h * len);
        }

        return result;
    }
};
