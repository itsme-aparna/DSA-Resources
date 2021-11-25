class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> freq_arr(32,0);
        
        for(int i=0; i<32; i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[j]&(1<<i)){
                    freq_arr[i]++;
                }
            }
        }
        
        int ans=0;
        for(int i=0; i<32; i++){
            if(freq_arr[i]%3!=0){
                ans = ((1<<i)|ans);
            }
        }
        return ans;
        
    }
};