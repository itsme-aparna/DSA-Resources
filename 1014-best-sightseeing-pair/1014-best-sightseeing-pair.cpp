class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int dp[n][2];
        for(int i=0; i<n; i++){
            dp[i][0] = values[i]+i;
            dp[i][1] = values[i]-i;
        }
        int ans = dp[0][0] + dp[1][1];
        int temp = max(dp[0][0], dp[1][0]);
        for(int i=2; i<n; i++){
            ans = max(ans, dp[i][1] + temp);
            temp = max(temp, dp[i][0]);
        }
        return ans;
    }
};
