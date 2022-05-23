class Solution {
public:
    bool check(vector<int>& nums, int sum, int idx, int cSum, vector<vector<int>>& dp){      
        if(idx == nums.size())
            return false;
        
        if(sum == 2*cSum)
            return true; 
        
        if(cSum > sum/2)
            return false;
        
        if(dp[idx][cSum] == -1){           
            dp[idx][cSum] = 0;
            if (check(nums, sum, idx+1, cSum+nums[idx], dp) || check(nums, sum, idx+1, cSum, dp))
                dp[idx][cSum] = 1;
        }
        
        return dp[idx][cSum] == 1;
            
        
        
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
            sum = sum + nums[i];
        
        if (!sum%2)
            return false;
        
        vector<vector<int>> dp (nums.size(), vector<int> (sum/2+1, -1));
        
        return check(nums, sum, 0, 0, dp);
        
    }
};