class Solution {
public:
    
    int solve(vector<int> &coins, int amt, vector<vector<int>>& dp, int n){
        if(n<0 || amt <=0){
            if(amt==0)
                return 0;
            return INT_MAX-1;
        }
        if(dp[n][amt]!=-1){
            return dp[n][amt];
        }
        // include
        if(coins[n]<=amt){
            return dp[n][amt] = min(solve(coins, amt, dp, n-1), 1+solve(coins, amt-coins[n], dp, n));
        }
        // exclude
        return dp[n][amt] = solve(coins, amt, dp, n-1);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        if(solve(coins, amount, dp, n-1)==INT_MAX-1)
            return -1;
        return solve(coins, amount, dp, n-1);
        
    }
};