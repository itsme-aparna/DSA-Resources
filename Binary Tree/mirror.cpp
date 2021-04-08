#include<bits/stdc++.h>
using namespace std;

int main() {
	int M = 3, N = 2;
 
    int u1[] = { 1, 1 };
    int v1[] = { 2, 3 };
 
    int u2[] = { 1, 1 };
    int v2[] = { 3, 2 };
 
    areMirrors(M, N, u1, v1, u2, v2);
 
    return 0;
}

bool areMirrors(int M, int N, int u1[], int v1[], int u2[], int v2[]){
     vector<stack<int>> s(M+1);
     vector<queue<int>> q(M+1);
     
     for(int i=0; i<N; i++){
         s[u1[i]].push(v1[i]);
         
     }
     
     for(int i=0; i<N; i++)
         q[u2[i]].push(v2[i]);
         
     for(int i = 1; i<s.size();++i){
         stack<int> s1 = s[i];
         queue<int> q1 = q[i];
         
         
         while(!s1.empty() && !q1.empty()){
             if(s1.top()!=q1.front())
                return false;
             s1.pop();
             q1.pop();
         }
         
         if(!s1.empty() || !q1.empty())
            return false;
    
     }
     
     return true;
     
}