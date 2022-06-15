class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = prices[0];
        int maxi = 0;
        for(auto i: prices){
            int mini = min(mini, i);
            maxi = max(maxi, i-mini);
        }
        return maxi;
    }
};