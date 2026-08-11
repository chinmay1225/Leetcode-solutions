class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxCount = 0;
        int maxRow = 0;
        
        for(int row = 0; row < n; row++){
            int count = 0;
            for(int col = 0 ; col < m; col++){
                if(mat[row][col] == 1){
                    count++;
                }
            }
            if(count > maxCount){
                maxCount = count;
                maxRow = row;
            }
        }
        return {maxRow , maxCount};
        
    }
};