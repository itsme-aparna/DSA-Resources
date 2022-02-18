class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        for(char c: num){
            while(!st.empty() && k>0 && c<st.top()){
                st.pop(); k--;
            }
            if(!st.empty() || c!='0'){
                st.push(c);
            }
        }
        
        while(k-- && !st.empty()){
            st.pop();
        }
        if(st.empty())
            return "0";
        
        
        while(!st.empty()){
            num[n-1] = st.top();
            st.pop();
            n--;
        }
        return num.substr(n);
        
        
    }
};