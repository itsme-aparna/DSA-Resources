class Solution {
public:
    
    bool isValid(int mid, vector<int>&weights, int D){
        int days = 1;
        int total=0;
        bool Valid = true;
        for(int i=0; i<weights.size(); i++){
            if(weights[i]>mid)
                Valid = false;
            if(total+weights[i]<=mid){
                total += weights[i];
                
            }
            else{
                days++;
                total = weights[i];
            }
        }
        if(!Valid){
            return false;
        }
        else{
            return (days<= D);
        }
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1;
        int r = 500*50000;
        while(l<r){
            int mid = (l+r)/2;
            if(isValid(mid, weights, days)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};