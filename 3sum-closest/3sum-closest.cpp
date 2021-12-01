class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // if(target<0){
        //     for(int i=0; i<nums.size(); i++){
        //         nums[i] = -1*nums[i];
        //     }
        // }
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        for(int i=0; i<nums.size()-2; i++){
            int j=i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target)
                    return target;
                if(abs(sum-target)<abs(ans-target)){
                    ans = sum;
                }
                
                if(sum>target){
                     k--;
                }
                else if(sum<target){
                    j++;
                }
            }
        }
        // if(target<0){
        //     return -1*ans;
        // }
        return ans;
        
    }
};