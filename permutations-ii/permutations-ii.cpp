class Solution {
public:
    
    void func(set<vector<int> > &set_of_vectors, int indx, vector<int>& nums){
        if(indx==nums.size()){
           set_of_vectors.insert(nums);
            return;
        }
        
        for(int i=indx; i<nums.size(); i++){ 
            swap(nums[i], nums[indx]);
            func(set_of_vectors, indx+1, nums);
            swap(nums[i], nums[indx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int> > set_of_vectors;
        func(set_of_vectors, 0, nums);
        for(auto i: set_of_vectors){
            ans.push_back(i);
        }
        return ans;
    }
};