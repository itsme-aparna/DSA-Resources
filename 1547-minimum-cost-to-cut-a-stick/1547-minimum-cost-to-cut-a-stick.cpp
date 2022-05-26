class Solution {
public:
    
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j)
            return 0;
        
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        
        
        for(int k =i; k<=j; k++){
            int steps = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
            mini = min(mini, steps);
        }
        
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int N = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        
        return solve(1, N, cuts, dp);
    }
};