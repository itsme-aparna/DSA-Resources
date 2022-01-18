class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int tillnow = 0;
        for(int i=0; i<nums.size(); i++){
            tillnow += nums[i];
            maxSum = max(maxSum, tillnow);
            if(tillnow<=0){
                tillnow = 0;
            }
        }
        return maxSum;
    }
};