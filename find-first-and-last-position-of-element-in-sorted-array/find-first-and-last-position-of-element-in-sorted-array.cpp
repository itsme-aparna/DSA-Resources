class Solution {
public:
    
    int lower_bound(vector<int>& nums, int target){
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo + ((hi-lo)>>1);
            if(nums[mid]<target){
                lo = mid+1;
            }
            else
                hi = mid-1;
            
        }
        return lo;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1, -1};
        }
        if(nums.size()==1){
            if(nums[0]==target){
                return {0,0};
            }
            else{
                return {-1,-1};
            }
        }
        int start = lower_bound(nums, target);
        int end = lower_bound(nums, target+1)-1;
        if(start>= nums.size() || nums[start]!=target){
            return {-1, -1};
        }
        return {start, end};
    }
};