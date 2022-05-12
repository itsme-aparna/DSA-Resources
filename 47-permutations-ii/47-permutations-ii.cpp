class Solution {
public:
    
    void func(set<vector<int>>& set, vector<int>& nums, int idx, int n){
        if(idx == n){
            set.insert(nums);
            return;
        }
        
        for(int i=idx; i<n; i++){
            swap(nums[i], nums[idx]);
            func(set, nums, idx+1, n);
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> set;
        int n = nums.size();
        func(set, nums, 0, n);
        for(auto i: set){
            ans.push_back(i);
        }
        
        return ans;
    }
};