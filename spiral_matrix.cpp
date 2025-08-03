class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int total = matrix.size() * matrix[0].size();
        int r = 0, c = 0;
        int r_min = 0, r_max = matrix.size() - 1;
        int c_min = 0, c_max = matrix[0].size() - 1;
        enum direction { R, D, L, U } DIR = R;
        
        while(result.size() < total){
            result.push_back(matrix[r][c]);

            switch(DIR){
                case R:
                    if(c == c_max){
                        DIR = D;
                        r++;
                        r_min++;
                    }else
                        c++;
                    break;
                case D:
                    if(r == r_max){
                        DIR = L;
                        c--;
                        c_max--;
                    }else
                        r++;
                    break;
                case L:
                    if(c == c_min){
                        DIR = U;
                        r--;
                        r_max--;
                    }else
                        c--;
                    break;
                case U:
                    if(r == r_min){
                        DIR = R;
                        c_min++;
                        c++;
                    }else
                        r--;
                    break;
            }
        }

        return result;
    }
};