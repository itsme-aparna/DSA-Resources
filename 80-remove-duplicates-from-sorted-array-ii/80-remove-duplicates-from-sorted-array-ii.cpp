class Solution {
public:
    
    //[1,1,1,2,2,3]
    
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1 || n==2){
            return n;
        }
        
        int freq = 0;
        int j =0;
        for(int i=0; i<nums.size(); i++){
            if(i==n-1){
                if(nums[i]!=nums[i-1]){
                    nums[j] = nums[i];
                    return j+1;
                }
            }
            if(nums[i]!=nums[i+1]){
                nums[j] = nums[i];
                j++;
                continue;
            }
            freq = 1;
            while(i+1<=n-1 && nums[i]==nums[i+1]){
                freq++; 
                i++;
            }
            if(freq>=2){
                nums[j] = nums[i];
                nums[j+1] = nums[i];
                j = j+2;
            }
            // if(freq==1){
            //     nums[j] = nums[]
            // }
        }
        return j;
    }
};