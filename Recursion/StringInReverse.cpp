#include <bits/stdc++.h>
using namespace std;

void reverse(string str, int n){
     if(n==0){
         return ;
     }

     reverse(str, n-1);
     cout<<str[n-1]<<endl;
     

}

int main(){
     string str = "binod";
     reverse(str, 5);
     return 0;
}
