class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int max_area = 0;
        while(l<r){
            int h1 = height[l];
            int h2 = height[r];
            int area = min(h1, h2)*(r-l);
            max_area = max(area, max_area);
            if(h1<h2){
                l++;
            }
            else{
                r--;
            }
        }
        return max_area;
    }
};