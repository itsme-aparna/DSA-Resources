#include<bits/stdc++.h>
using namespace std;

void checkSides(char &island[R][C], int x, int y){
    if(island[x][y-1]=='.'){ 
    if((island[x-1][y]=='.' && island[x+1][y] == '.' ) || (island[x-1][y]=='.' && island[x][y+1]) || (island([x][y+1]=='.' && island[x+1][y]) )){
        island[x][y]=='.';
        return;
    }
        }
    else if(island[x][y-1] != '.'){
        if(island[x-1][y] =='.' && island[x+1][y] =='.' && island[x][y+1] == '.'){
            island[x][y]=='.';
            return;
        }
    }
    return;
}



int main() {

	int R,C;
    cin>>R>>C;
    char x;
    char island [R+1][C+1];
    for(int i=0; i<R; i++){
        island[i][0] = '.';
        island[i][C] = '.';
    }
    for(int i=0; i<C; i++){
        island[0][i] = '.';
        island[R][i];
    }
    for(int i=1; i<R; i++){
        for(int j=1; j<C; j++){
            cin>>island[i][j];
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(island[i][j] == 'X')
                 checkSides(island, i, j);
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(island[i][j+1]=='X' || island[i][j-1]=='X' || island[i-1][j]=='X' || island[i+1][j]=='X'){
                cout<<island[i][j];
            }
        }
    }
    return 0;
}


