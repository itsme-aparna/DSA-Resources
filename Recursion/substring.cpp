#include <bits/stdc++.h>
using namespace std;

string subString(string str){
    if(str.length()==0)
      return " ";
    
    string ans = subString(str.substr(0, str.length()-1));
    cout<<str<<endl;
    return ans;
}

int main(){
    subString("Aparna");
    
    return 0;
}