// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  string ans = "";
  int n = 1;
  int i=0;
  for(; i<src.length()-1; i++){
      if(src[i]==src[i+1]){
          n++;
      }
      else{
          ans += src[i]+ to_string(n);
          n = 1;
      }
  }
  ans += src[i]+ to_string(n);
  return ans;
}     
 
