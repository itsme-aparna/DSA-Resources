// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        string ans = "";
        stack<int> st;
        int n = 1;
        for(int i=0; i<S.length(); i++){
            if(S[i]=='D'){
                st.push(n);
                n++;
            }
            else{
                st.push(n);
                n++;
                while(!st.empty()){
                    ans+= to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(n);
                
        while(!st.empty()){
            ans+= to_string(st.top());
            st.pop();
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends