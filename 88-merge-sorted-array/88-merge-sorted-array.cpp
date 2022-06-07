class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j = 0;
        
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                i++;
            }
            else{
                swap(nums1[i], nums2[j]);
                sort(nums2.begin(), nums2.end());
                i++;
            }
        }
        j = 0;
        for(int i=m; i<n+m; i++){
            nums1[i] = nums2[j++];
        }
    }
};