class Solution {
public:
    bool check(string& a,string& b){
        if(a.length()!=b.length()-1)return false;
        int count=0;
        int i=0,j=0;
        while(i<a.length() && j<b.length()){
            if(a[i]!=b[j]){
                if( count==1)return false;
                count=1;
            }
            else i++;
            j++;
        }
        return true;
    }
    
    int solve(vector<string>& words,int index,int prev,vector<int>& dp){
       if(index>=words.size())return 0;
        if(dp[prev]!=-1)return dp[index];
        int include=0;
        
        if(prev==0 || check(words[prev-1],words[index])){
            include=1+solve(words,index+1,index+1,dp);
        }
        
        int notinclude=solve(words,index+1,prev,dp);
        return dp[prev]=max(include,notinclude);
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),mysort);
        int n=words.size();
        vector<int> dp(n+1,-1);
        return solve(words,0,0,dp);
        
    }
    static bool mysort(string& a,string& b){
        return a.length()<b.length();
    }
};