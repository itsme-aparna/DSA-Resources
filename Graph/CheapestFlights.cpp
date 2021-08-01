#include <bits/stdc++.h>
using namespace std;

string maximumNumber(string num, vector<int>& change) {
        string newStr = "";
        for(int i=0; i<num.length(); i++){
            if((num[i]-'0')<change[(num[i]-'0')]){
                
                if(i==0){
                    newStr = to_string(change[num[i]-'0']) + num.substr(1, num.length()-1);
                }
                if(i==num.length()-1){
                    newStr = num.substr(0, num.length()-2)+to_string(change[num[i]-'0']);
                }
                else{ 
                newStr = num.substr(0, i-1) + to_string(change[num[i]-'0']) + num.substr(i+1, num.length()-1);
                    }
            }
        }
               return newStr;
    }

    int main(){
        string m;
        vector<int> change;
        cin>>m;
        for(int i=0; i<10; i++){
            cin>>change[i];
        }
        maximumNumber(m , change);
        return 0;
    }

