class Solution {
public:
    
    void func(vector<int>& nums, set<vector<int>>& set, vector<int> temp, int n, int idx){
        if(idx== n){
            sort(temp.begin(), temp.end());
            set.insert(temp);
            return;
        }
        
        temp.push_back(nums[idx]);
        func(nums, set, temp, n, idx+1);
        temp.pop_back();
        
        func(nums, set, temp, n, idx+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> set;
        vector<int> temp;
        vector<vector<int>> vec;
        int n = nums.size();
        func(nums, set, temp, n, 0);
        for(auto i: set){
            vec.push_back(i);
            
        }
        
        return vec;
    }
};