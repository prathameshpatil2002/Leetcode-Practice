class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,int>row,col;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]==0){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(auto it : row){
            for(int i=0;i<m;i++){
                matrix[it.first][i] = 0;
            }
        }
        for(auto it : col){
            for(int i=0;i<n;i++){
                matrix[i][it.first] = 0;
            }
        }
    }
};