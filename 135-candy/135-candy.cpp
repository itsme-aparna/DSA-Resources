class Solution {
public:
    int candy(vector<int>& ratings) {
        // greedy approach
        int n = ratings.size();
        
        vector<int> forward(n, 1);
        vector<int> backward(n, 1);
        
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                forward[i] = forward[i-1] + 1;
            }
        }
        
        for(int i= n-1; i>0; i--){
            if(ratings[i-1] > ratings[i]){
                backward[i-1] = backward[i] + 1;
            }
        }
        
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += max(forward[i], backward[i]);
        }
        return sum;
    }
};