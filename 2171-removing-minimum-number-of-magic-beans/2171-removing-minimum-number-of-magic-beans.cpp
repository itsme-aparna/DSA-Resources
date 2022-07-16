class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long n = beans.size();
        sort(beans.begin(), beans.end());
        reverse(beans.begin(), beans.end());
        long long sum = 0;
        for(int i=0; i<beans.size(); i++){
            sum += beans[i];
        }
        
        long long ans = 99999999999999;
        for(long long i=0; i<beans.size(); i++){
            ans = min(ans, sum - beans[i]*(i+1));
        }
        return ans;
    }
};