class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> x = nums;
        sort(nums.begin(), nums.end());
        int n1 = 0;
        int n2 = 0;
        if(x==nums){
            return 0;
        }
        for(int i=0; i<nums.size(); i++){
            if(x[i]!=nums[i]){
                n1 = i;
                break;
            }
            
        }
        
        for(int i=nums.size()-1; i>0; i--){
            if(x[i]!= nums[i]){
                n2 = i;
                break;
            }
        }
        
        return n2-n1 + 1;
    }
};