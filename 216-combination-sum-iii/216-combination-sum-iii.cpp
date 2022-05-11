class Solution {
public:
    
    void func(vector<vector<int>> &ans, vector<int> &ds, int k, int n, int idx){
        if(k==0 && n==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx+1; i<=9; i++){
            ds.push_back(i);
            func(ans, ds, k-1, n-i, i);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(ans, ds, k, n, 0);
        return ans;
    }
};