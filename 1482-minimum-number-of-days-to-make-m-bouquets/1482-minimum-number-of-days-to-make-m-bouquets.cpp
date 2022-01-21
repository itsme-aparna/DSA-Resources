class Solution {
public:
    int result(vector<int>& bloomDay, int days, int k){
        int c = 0;
        int r = 0;
        
        for(int i=0; i<bloomDay.size(); i++){
            if(days >= bloomDay[i]){
                c++;
            }
            else{
                c=0;
            }
            if(c==k){
                r++;
                c=0;
            }
        }
        return r;
    }
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size()){
            return -1;
        }
        int i = *min_element(bloomDay.begin(), bloomDay.end());
        int j = *max_element(bloomDay.begin(), bloomDay.end());
        while(i<j){
            int mid =  (j+i)>>1;
            if(result(bloomDay, mid, k)<m){
                i = mid+1;
            }
            else{
                j = mid;
            }
            
        }
        
        return i;
        
    }
};