class Solution {
public:
    void comb(vector<vector<int>> &ans, vector<int>& candidates, int target, int idx, vector<int> &ds){
        if(idx==candidates.size()){
            if(target==0){
            ans.push_back(ds);
            
        }
            return;
        }
        
        //pick and dont pick
        
        
        
        //target>=candidates[idx]
        if(target>=candidates[idx]){
             ds.push_back(candidates[idx]);
            
            comb(ans, candidates, target-candidates[idx], idx, ds);
            ds.pop_back();
        }
        comb(ans, candidates, target, idx+1, ds);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // try all combinations
        vector<vector<int>> ans;
        vector<int> ds;
        comb(ans, candidates, target, 0, ds);
        return ans;
    }
};