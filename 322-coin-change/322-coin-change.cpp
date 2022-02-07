class Solution {
public:
    
    int recur(vector<int>& coins, int amount, int idx, vector<vector<int>>& memo){
        if(idx==0 || amount== 0){
            return amount==0 ? 0 : INT_MAX-1;
        }
        if(memo[amount][idx]!=-1){
            return memo[amount][idx];
        }
        if(amount >= coins[idx-1]){
            //both
            return memo[amount][idx] = min((1+recur(coins, amount-coins[idx-1], idx, memo)), recur(coins, amount, idx-1, memo));
        }
        else{
            //exlude
            return memo[amount][idx] = recur(coins, amount, idx-1, memo);
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int ans;
        //include or exclude
        
        int n = coins.size();
        vector<vector<int>> memo(amount+1, vector<int>(n+1, -1));
        
        ans = recur(coins, amount, coins.size(), memo);
        if(ans==INT_MAX-1){
            return -1;
        }
        return ans;
    }
};