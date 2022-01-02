class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int N = nums.size();
        if(k==0) return 0;
        long i=0;
        int prod = 1;
        int count = 0;
        for(int j=0; j<N; j++){
            prod *= nums[j];
            while(i<=j && prod >= k){
                prod/= nums[i++];
            }
            count+= j-i+1;
        }
        return count;
    }
};