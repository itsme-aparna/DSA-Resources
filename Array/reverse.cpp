#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    
    int n = str.length();
    char temp;
    for(int i=0; i<n/2; i++){
        temp = str[i];
        str[i] = str[n-i-1];
        str[n - i -1] = temp;
        
    }
    return str;
}