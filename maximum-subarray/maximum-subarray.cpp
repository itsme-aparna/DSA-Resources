class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int max_till_here = 0;
        for(int i=0; i<nums.size(); i++){
            max_till_here +=nums[i];
            max_sum = max(max_sum, max_till_here);
            if(max_till_here<=0){
                max_till_here = 0;
            }
        }
        return max_sum;
    }
};