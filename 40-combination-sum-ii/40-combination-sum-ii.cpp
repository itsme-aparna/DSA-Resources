class Solution {
public:
    
    void func(vector<vector<int>> &ans, vector<int> &ds, int idx, int target, vector<int>& candidates){
            if(target==0){
                ans.push_back(ds);
            }
        
        
            for(int i=idx; i<candidates.size(); i++){
                if(i>idx && candidates[i]==candidates[i-1]){
                    continue;
                }
                if(candidates[i]>target)
                    break;
                
                ds.push_back(candidates[i]);
                func(ans, ds, i+1, target-candidates[i], candidates);
                ds.pop_back();
            }
        
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        func(ans, ds, 0, target, candidates);
        
        return ans;
    }
};