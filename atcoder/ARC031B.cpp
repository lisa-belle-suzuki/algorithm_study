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

const long long int INF = 1e14;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define Rep(i, n) for(int i = 1; i <= (int)(n); i++)
#define llrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define llRep(i, n) for(ll i = 1; i <= (ll)(n); i++)

using namespace std;

bool vector_finder(std::vector<int> vec, int number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
    }
  else { // 発見できなかったとき
    return false;
    }
}

bool isLand[12][12];
bool visited[12][12];

void search(int x, int y){
    if (x<0 || y<0 || x >= 10 || y >= 10) return;
    if (!isLand[x][y]) return;
    if(visited[x][y]) return;
    visited[x][y]=true;

    search(x+1,y);
    search(x-1,y);
    search(x,y+1);
    search(x,y-1);
}

bool isAllLandVisited(){
    rep(i,10){
        rep(j,10){
            if (isLand[i][j] && !visited[i][j]){              
                return false;
            }
        }
    }
    return true;
}




int main(){
    rep(i,12){
        rep(j,12){
            isLand[i][j]=false;
            visited[i][j]=false;
        }
    }
    char c;
    rep(i,10){
        rep(j,10){
            cin >> c;
            isLand[i][j] = (c =='o');
        }
    }

    rep(i,10){
        rep(j,10){
            if (!isLand[i][j]){
                rep(x,10){
                    rep(y,10){
                        visited[x][y]=false;
                    }
                }
                search(i-1,j);
                search(i+1,j);
                search(i,j-1);
                search(i,j+1);

                if (isAllLandVisited()){
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
