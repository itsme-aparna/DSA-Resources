class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int r = INT_MIN;
        int max_val = 1;
        int min_val = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                swap(max_val, min_val);
            }
            max_val = max(nums[i]*max_val, nums[i]);
            min_val = min(nums[i]*min_val, nums[i]);
            
            r = max(r, max_val);
        }
        return r;
    }
};