class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        bool arr1[101]={0};
        bool arr2[101]={0};
        bool arr3[101]={0};
        for(const auto &i:nums1) arr1[i]=true;
        for(const auto &i:nums2) arr2[i]=true;
        for(const auto &i:nums3) arr3[i]=true;
        vector<int> ans;
        for(int i=1;i<=100;++i){
            if((arr1[i] and arr2[i]) or (arr2[i] and arr3[i]) or (arr3[i] and arr1[i])) ans.push_back(i);
        }
        return ans;
    }
};