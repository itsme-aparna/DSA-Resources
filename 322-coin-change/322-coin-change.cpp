class Solution {
public:
    
    int solve(vector<int>& coins, int amount, int idx, vector<vector<int> > &memo){
       if(amount<=0  || idx >= coins.size()){
           if(amount == 0){
               return 0;
           }
           else{
               return INT_MAX-1;
           }
           
       }
        
       if(memo[amount][idx] != -1){
           return memo[amount][idx];
       }
        
       
        
        if(amount >= coins[idx])
            return memo[amount][idx] = min( 1+ solve(coins, amount- coins[idx], idx, memo), solve(coins, amount, idx+1, memo));
        
        else
            return memo[amount][idx] = solve(coins, amount, idx+1, memo);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // try all combinations
        // write the recursive code first - done
        // memoize
        
         vector<vector<int> > memo(amount + 1, vector<int> (coins.size(), -1));
        if(solve(coins, amount, 0, memo)== INT_MAX-1){
            return -1;
        }
        return solve(coins, amount, 0, memo);
    }
};