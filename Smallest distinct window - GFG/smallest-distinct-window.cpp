// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        int n = str.size();
        set<int> s;
        for(int i=0; i<n; i++){
            s.insert(str[i]);
        }
        int cnt = s.size();
        string pat = "";
        for(auto i = s.begin(); i!=s.end(); i++){
            pat += (*i);
        }
        
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        
        for(int i=0; i<cnt; i++){
            mp1[pat[i]]++;
        }
        
        int uni = 0;
        int i = 0;
        int len = INT_MAX;
        for(int j=0; j<n; j++){
            if(mp2[str[j]]==0){
                uni++;
                
            }
            mp2[str[j]]++;
            while(uni >= cnt){
                mp2[str[i]]--;
                
                
                
                
                
                int len1 = j-i+1;
                if(len1<len && uni==cnt){
                    len = len1;
                    
                }
                if(mp2[str[i]]==0){
                    uni--;
                }
                i++;
            }
            
            
            
        }
        if(len == INT_MAX){
            return str.size();
        }
        return len;
        
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends