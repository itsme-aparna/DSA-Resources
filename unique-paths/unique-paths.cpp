class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        for(int i=m; i>=1; i--){
            for(int j=n; j>=1; j--){
                if(i==m && j==n)
                    dp[i][j] = 1;
                else
                {int opt1 = (i==m)?0:dp[i+1][j];
                int opt2 = (j==n)?0:dp[i][j+1];
                dp[i][j] = opt1+opt2;}
            }
        }
        return dp[1][1];
    }
};