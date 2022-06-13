class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> vec = triangle;
        
        for(int i=1; i<n; i++){
            for(int j = 0; j<triangle[i].size(); j++){
                if(j ==0){
                    vec[i][j] = vec[i-1][j] + triangle[i][j];
                }
                else if(j== triangle[i].size()-1){
                    vec[i][j] = vec[i-1][j-1] + triangle[i][j];
                }
                else{
                    vec[i][j] = min(vec[i-1][j], vec[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        
        int ans = vec[n-1][0];
        for(auto i: vec[n-1]){
            ans = min(ans, i);
        }
        return ans;
    }
};