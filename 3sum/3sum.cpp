class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if(n<=2)
            return {};
        if(n==3){ 
            
            if(nums[1]+nums[2]+nums[0]==0){
                ans.push_back({nums[0], nums[1], nums[2]});
                
                return ans;
            }
            else{
                return {};
            }
        }
        
        set<vector<int>> st;
        for(int i=0; i<n-2;i++){
            int l = i+1;
            int r = n-1;
            
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    
                    st.insert({nums[i], nums[l], nums[r]});
                    l++; r--;
                }
                
                else if(nums[i]+nums[l]+nums[r]<0){
                    l++;
                }
                else{
                    r--;
                }
                
            }
        }
        
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
        
    }
};