class Solution {
public:
    int countHousePlacements(int n) {
        long long mod = 1e9+7;
        vector<long long> dp(n+1);
        dp[0] = 2;
        dp[1] = 3;
        
        for(int i=2; i<n; i++){
            dp[i] =( dp[i-1] + dp[i-2])%mod;
        }
        
        return (dp[n-1]*dp[n-1]) % mod;
    }
};