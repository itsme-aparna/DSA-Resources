class Solution {
    public:
    int findMin(vector<int> nums) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j){
		
            while(i+1<n && nums[i]==nums[i+1]) i++;
            while(j-1>=0 && nums[j-1]==nums[j]) j--;
			
            int mid=i+(j-i)/2;
            if(nums[j]<nums[mid]) i=mid+1;
            else j=mid;
        }
        return nums[i];
    }
};


