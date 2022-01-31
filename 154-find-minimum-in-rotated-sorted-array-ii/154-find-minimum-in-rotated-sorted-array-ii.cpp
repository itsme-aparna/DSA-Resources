class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        
        while(lo<hi){
            
            while(lo+1<nums.size() && nums[lo]==nums[lo+1]){
                
                    lo++;
            }
            while(hi-1>=0 && nums[hi]==nums[hi-1]){
                hi--;
            }
            
            int mid = lo + ((hi-lo)>>1);
            if(nums[hi]<nums[mid]){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        return nums[lo];
    }
};