class Solution {
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX/2));
        for(auto &i: edges){
            dp[i[0]][i[1]] = i[2];
            dp[i[1]][i[0]] = i[2];
        }
		for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    dp[j][k] = min(dp[j][k], dp[j][i]+dp[i][k]);
                }
            }
        }
        
        int ans=-1;
		int cur=INT_MAX;
		for(int i=0;i<n;i++){
			int count=0;
			for(int j=0;j<n;j++){
				if(j!=i && dp[i][j]<=distanceThreshold){
					count++;
				}
			}
			if(count<=cur){
				cur=count;
				ans=i;
			}
		}
		return ans;
	}
};