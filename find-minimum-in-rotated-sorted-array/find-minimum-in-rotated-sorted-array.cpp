class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int low = 0;
        
        int high = nums.size()-1;
        while(low<high){
            int mid = (low+high)>>1;
            if(nums[mid]>nums[high])
                low = mid+1;
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};


