class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==1 && nums[0]==target){
            return true;
        }
        if(nums.size()==1 && nums[0]!=target){
            return false;
        }
        int l =0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(target == nums[mid]){
                return true;
            }
            if(nums[l]<nums[mid]){
                if(target<=nums[mid] && target>=nums[l]){
                    r = mid-1;
                }
                else
                    l = mid+1;
            }
            else if(nums[r]>nums[mid]){
                if(target>= nums[mid] && target<= nums[r]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            else{
                if(nums[l]==nums[mid])
                    l++;
                if(nums[r]==nums[mid])
                    r--;
            }
        }
        return false;
    }
};