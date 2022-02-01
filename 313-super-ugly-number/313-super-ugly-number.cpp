class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, 0);
        vector<int> pointer(primes.size(), 0);
        dp[0] = 1;
        for(int i=1; i<n; i++){
            int mini = INT_MAX;
            for(int j=0; j<primes.size(); j++){
                mini = min(mini, dp[pointer[j]]*primes[j]);
            }
            dp[i] = mini;
            for(int j=0; j<primes.size(); j++){
                if(mini == dp[pointer[j]]*primes[j]){
                    pointer[j]++;
                }
            }
        }
        return dp[n-1];
    }
};
