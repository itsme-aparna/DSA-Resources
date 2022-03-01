class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int count=0;
        for(int i=0; i<n+1; i++){
            int x = i;
            while(x){
                count++;
                x = x&(x-1);
            }
            ans.push_back(count);
            count=0;
        }
        return ans;
    }
};