class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int size = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i]==0)?-1:1;
            if(sum==0){
                size = i+1;
            }
            else if(mp.find(sum)!=mp.end()){
                size = max(size, abs(i-mp[sum]));
            }
            else{
                mp[sum]=i;
            }
        }
        return size;
    }
};