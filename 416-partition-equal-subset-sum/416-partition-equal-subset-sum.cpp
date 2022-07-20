class Solution {
public:
    int subsetSum(vector<int> &nums, int n, int target, vector<vector<int>>& dp){
        if(target==0 || n==0){
            if(target !=0)
                return 0;
            return 1;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        if(nums[n]<=target){
            return dp[n][target] = subsetSum(nums, n-1, target, dp)||subsetSum(nums, n-1, target-nums[n], dp);
        }
        return dp[n][target] = subsetSum(nums, n-1, target, dp);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        if(sum%2 != 0){
            return false;
        }
        
        else{
            vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
            return subsetSum(nums, n-1, sum/2, dp);
        }
    }
};