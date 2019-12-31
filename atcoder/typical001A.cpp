# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>
#include <numeric>

const long long int INF = 1e14;
typedef long long int ll;
#define rep(i,n) for(ll i=0; i<n; i++)
#define Rep(i,n) for(ll i=1; i<=n; i++)
// #define orep(i,s,e) for(ll i=s; i<e; i++)
// #define oRep(i,s,e) for(ll i=s; i<=e; i++)

using namespace std;


ll H, W, sx, sy, gx, gy;
char c;
char maze[504][504];//迷路
bool reached[504][504];


void search(ll x, ll y){
    if (maze[x][y] == '#' || x < 0 || y < 0 || x >= H || y >= W ) return;
    if (reached[x][y] == true) return;
    reached[x][y] = true;

    search(x-1, y);
    search(x+1, y);
    search(x, y-1);
    search(x, y+1);
}

int main() {

    cin >> H >> W;
    rep(i,H){
        rep(j,W){
            cin >> c;
            maze[i][j] = c;
            if (c=='s'){ sx = i; sy = j;}
            if (c=='g'){ gx = i; gy = j;}
        }
    }
    search(sx, sy);

    if (reached[gx][gy]==true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
