class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //min sum
        //min(all the three points)
        vector<vector<int>> vec(n, vector<int> (m, INT_MAX));
        for(int i=0; i<n; i++){
            vec[0][i] = matrix[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(j>0 && j<m-1){
                    int mini = min(vec[i-1][j-1], vec[i-1][j]);
                    mini = min(mini, vec[i-1][j+1]);
                    vec[i][j] = mini + matrix[i][j];
                }
                else if(j==0){
                    vec[i][j] = min(vec[i-1][j], vec[i-1][j+1]) + matrix[i][j];
                }
                else if(j==m-1){
                    vec[i][j] = min(vec[i-1][j], vec[i-1][j-1]) + matrix[i][j];
                }
                
            }
        }
        int ans = INT_MAX;
        for(auto& x:vec[vec.size()-1]){
            ans = min(ans,x);
    }
        return ans;
    }
};