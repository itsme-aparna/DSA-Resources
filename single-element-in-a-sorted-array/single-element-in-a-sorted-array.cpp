class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low=0;
        int high = nums.size()-1;
        if(n==1)
            return nums[0];
        
        if(nums[0]!= nums[1]){
            return nums[0];
        }
        if(nums[n-1]!= nums[n-2]){
            return nums[n-1];
        }
        
        while(low<=high){
            int mid = (high+low)>>1;
        
            if(nums[mid]==nums[mid-1] && mid){
                if(((mid-low)&1) == 0){
                    high = mid-2;
                }
                else{
                    low = mid+1;
                }
            }
            else if(nums[mid]==nums[mid+1] && mid+1 < n){
                if(((mid-low)&1) == 0){
                    low = mid+2;
                }
                else{
                    high = mid-1;
                }
            }
            else{
                return nums[mid];
            }
            
            
        }
        return -1;
    }
};