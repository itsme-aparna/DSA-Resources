class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int l1 = 0;
        int l2 = colors.size()-1;
        if(colors[l1]!= colors[l2]){
            return l2-l1;
            
        }
        int maxi;
        
        
            if(colors[l1]== colors[l2]){
                int x = l1;
                int y = l2;
                while(colors[l1]==colors[l1+1]){
                    l1++;
                }
                l1 = l1+1;
                int dist1 = abs(y-l1);
                while(colors[l2]==colors[l2-1]){
                    l2--;
                }
                l2 = l2-1;
                int dist2 = abs(x-l2);
                maxi = max(dist1, dist2);
                
            }
            
            
                
                
            
        
        return maxi;
    }
};