class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int lSmall[n], rSmall[n];
        stack<int> st;
        
        //The stack is used to store the elements in linearly increasing fashion
        //This way we can figure out the previous smaller element.
        
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            
            if(st.empty())
                lSmall[i] = 0;
            else
                lSmall[i] = st.top()+1;
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            
            if(st.empty())
                rSmall[i] = n-1;
            else
                rSmall[i] = st.top()-1;
            st.push(i);
        }
        
        int maxA = 0;
        for(int i=0; i<n; i++){
            maxA = max(maxA, heights[i]*(rSmall[i] -lSmall[i] + 1));
        }
        
        return maxA;
    }
};