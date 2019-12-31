#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define Rep(i, n) for(int i = 1; i <= (int)(n); i++)

const long long int INF = 1e14;
typedef long long int ll;

using namespace std;

char bomb[52][52];
char count[52][52];

// -1,1
// 0,1
// 1,1
// -1,0
// 1,0
// -1,-1
// 0,-1
// 1,-1

int x_diff[] = {-1,0,1,-1,1,-1,0,1};
int y_diff[] = {1,1,1,0,0,-1,-1,-1};

int main(){
    int H,W;
    char c;
    cin >> H >> W;

    rep(i,H){
        rep(j,W){
            cin >> c;
            bomb[i][j] = c;
        }
    }
    rep(i,H){
        rep(j,W){
            if(bomb[i][j]=='#') cout << '#';
            else{
                int cnt=0;
                rep(k,8){
                    int x = i + x_diff[k];
                    int y = j + y_diff[k];
                    if (x<0||y<0||x>=H||y>=W) continue;
                    if (bomb[x][y]=='#') cnt ++;
                }
                cout << cnt;
            }
        }
        cout << "" << endl;
    }

    return 0;
}
