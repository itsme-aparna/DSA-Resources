class Solution {
public:
    int findcnt(int n){
        if(n ==0)
            return 0;
        int cnt = 0;
        while(n){
            if(n&1 == 1) break;
            cnt++;
            n = n>>1;
        }
        return cnt;
    }
    vector<int> singleNumber(vector<int>& nums) {
        long long n = 0;
        for(int i=0; i<nums.size(); i++){
            n = n^nums[i];
        }
        
        // 
        int cnt = findcnt(n);
        int xor1 = 0, xor2 = 0;
        for(auto i: nums){
            if(i & (1<<cnt)){
                xor1 ^= i;
            }
            else{
                xor2 ^= i;
            }
        }
        
        return {xor1, xor2};
    }
};