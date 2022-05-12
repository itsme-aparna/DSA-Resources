class Solution {
public:
    
    void func(vector<vector<int>> &ans, vector<int> &ds, vector<int>& candidates, int target, int sum, int idx, int n){
        if(idx==n){
            if(sum == target){
                ans.push_back(ds);
            }
            return;
        }
        
        //pick
        
        if(sum+candidates[idx] <=target){
            sum+= candidates[idx];
            ds.push_back(candidates[idx]);
            func(ans, ds, candidates, target, sum, idx, n);
            ds.pop_back();
            sum -= candidates[idx];
            
        }
        
        
        
        
        //not pick
        func(ans, ds, candidates, target, sum, idx+1, n);
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        func(ans, ds, candidates, target, 0, 0, n);
        return ans;
    }
};