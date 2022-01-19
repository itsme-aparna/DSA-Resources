class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //take transpose
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix[0].size(); j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        for(int i=0; i<matrix.size(); i++){
            int j = 0;
            int last = matrix[0].size()-1;
            while(j<last){
                swap(matrix[i][j], matrix[i][last]);
                j++;
                last--;
            }
        }
    }
};