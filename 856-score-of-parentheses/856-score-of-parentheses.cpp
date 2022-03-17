class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(ans);
                ans = 0;
            }
            
            else{
                ans += st.top() + max(ans, 1);
                st.pop();
                
            }
        }
        
        return ans;
    }
};