class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int small = INT_MAX;
        int large = -1;
        for(int i=0; i<nums.size(); i++){
            small = min(small, nums[i]);
            if(i>0 && nums[i]-small>0)
          
                large = max(large, nums[i]-small);
        }
        return large;
    }
};