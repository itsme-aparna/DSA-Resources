class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int size = n+1;
        int sum = 0;
        while(r<n){
            while(r<n && sum<target){
                sum+= nums[r];
                r++;
                
            }
            while(l<n && sum>=target){
                size = min(size, r-l);
                sum-= nums[l];
                l++;
            }
            
        }
        if(size== n+1) return 0;
        return size;
    }
    
};


