class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<int> st;
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                cnt++;
            }
            
            if(s[i] == ')'){
                if(cnt != 0){
                    cnt--;
                }
                else{
                    s[i] = '#';
                }
            }
        }
        
        cnt = 0;
        for(int i= s.length()-1; i>=0; i--){
            if(s[i] == ')'){
                cnt++;
            }
            
            if(s[i] == '('){
                if(cnt == 0){
                    s[i] = '#';
                }
                else{
                    cnt--;
                }
            }
        }
        
        
        for(int i=0; i<s.length(); i++){
            if(s[i] != '#'){
                ans+= s[i];
            }
        }
        
        return ans;
    }
};