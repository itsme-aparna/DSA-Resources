class Solution {
public:
    
    void solve(vector<vector<int>> &ans, vector<int>& temp, vector<int>& nums, int idx){
        ans.push_back(temp);
        for(int i=idx; i<nums.size(); i++){
            if(i!= idx && nums[i]==nums[i-1]){
                continue;
            }
            
            temp.push_back(nums[i]);
            solve(ans, temp, nums, i+1);
            temp.pop_back();
            
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(nums.begin(), nums.end());
        solve(ans, temp, nums, 0);
        return ans;
    }
};