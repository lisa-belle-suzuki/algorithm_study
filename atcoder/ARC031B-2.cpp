# include <bits/stdc++.h>

using namespace std;

int original_states[10][10];//0:海，1:島(未到達)，2:島(到達済)
int new_states[10][10];


void res(int x, int y){
    if (new_states[x][y] != 1) return;
    new_states[x][y] = 2;
    res(x+1,y);
    res(x-1,y);
    res(x,y+1);
    res(x,y-1);
}


int main(){
    char st;
    for(int i=0; i<10; i++){
        for(int j=0; j<10;j++){
            cin >> st;
            if (st=='x') original_states[i][j] = 0;
            else original_states[i][j] = 1;
        }
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10;j++){
            memcpy(new_states, original_states, sizeof(original_states));
            new_states[i][j] = 1;
            res(i,j);
            bool isOneIsland = true;
            for(int k=0; k<10; k++){
                for (int l=0;l<10;l++){
                    if (new_states[k][l]==1){
                        isOneIsland = false;
                    }
                }
            }
            if (isOneIsland){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}