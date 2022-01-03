class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]!= ']')
                st.push(s[i]);
            else{
                string curr = "";
                while(st.top()!= '['){
                    curr = st.top() + curr;
                    st.pop();
                }
                
                st.pop();
                string num = "";
                
                while(!st.empty() && isdigit(st.top())){
                    num = st.top()+num;
                    st.pop();
                }
                
                int number = stoi(num);
                
                while(number--){
                    for(int j =0; j<curr.size(); j++){
                        st.push(curr[j]);
                    }
                }
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans = st.top()+ ans;
            st.pop();
        }
        return ans;
        
    }
};




