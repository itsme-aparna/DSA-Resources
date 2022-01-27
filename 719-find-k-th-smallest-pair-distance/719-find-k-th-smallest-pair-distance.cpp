class Solution {
public:
    
    bool ok(int mid, vector<int>& nums, int k){
        
        int n = nums.size();
        int total = 0;
        int j=1;
        for(int i=0; i<n; i++){
            while(j<n && nums[j]-nums[i]<=mid)
                j++;
            j--;
            int x = j-i;
            total += x;
            
                
        }
        return (total>=k);
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int low = 0;
        int high = maxi-mini;
        
        while(low<high){
            int mid = (low+high)/2;
            if(ok(mid, nums, k)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};