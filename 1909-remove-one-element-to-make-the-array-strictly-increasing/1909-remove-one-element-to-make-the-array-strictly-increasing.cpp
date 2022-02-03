class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int prev = nums[0];
        int cnt = 1;
        for(int i=1; i<nums.size(); i++){
            if(prev >= nums[i]){
                if(cnt==0){
                    return false;
                }
                cnt--;
                if (i == 1 || nums[i] > nums[i - 2]) 
                prev = nums[i];
            }
            else
                prev = nums[i];
        }
        return true;
    }
};
