class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1){
            return;
        }
        if(k>nums.size()){
            while(k>nums.size()){
                k = k-nums.size();
            }
        }
        vector<int> ans;
        //7-3 = 4
        int n = nums.size()-k;
        for(int i=n; i<nums.size(); i++){
            ans.push_back(nums[i]);
        }
        for(int i=0; i<n; i++){
            ans.push_back(nums[i]);
        }
        nums = ans;
    }
};