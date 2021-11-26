class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int n = 0;
        for(int i=0; i<nums.size(); i++){
            n = n^nums[i];
        }
        
        int mask = n & (~(n-1));
        int xor1 = 0; int xor2 = 0;
        for(auto i: nums){
            if(mask&i)
                xor1 = xor1^i;
            else{
                xor2 = xor2^i;
            }
        }
        return {xor1, xor2};
            
    }
};