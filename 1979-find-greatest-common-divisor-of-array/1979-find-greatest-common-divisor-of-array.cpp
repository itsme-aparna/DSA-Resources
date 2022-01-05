class Solution {
public:
    
    int gcd(int n, int m){
        if(m==0)
            return n;
        return gcd(m, n%m);
    }
    
    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        return gcd(maxi, mini);
    }
};