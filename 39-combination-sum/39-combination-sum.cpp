class Solution {
public:
    
    void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int>& candidates, int idx, int target, int sum, int n){
        
        if(idx== n || sum == target){
            if(sum == target){
                ans.push_back(temp);
            }
            
            return;
        }
        
        if(sum + candidates[idx] <= target){
            sum = sum + candidates[idx];
            temp.push_back(candidates[idx]);
            
            solve(ans, temp, candidates, idx, target, sum, n);
            temp.pop_back();
            sum -= candidates[idx];
        }
        
        
        solve(ans, temp, candidates, idx+1, target, sum, n);
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        solve(ans, temp, candidates, 0, target, 0, n);
        return ans;
    }
};