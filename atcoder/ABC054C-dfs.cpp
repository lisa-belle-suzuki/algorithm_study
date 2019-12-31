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

const long long int INF = 1e9;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define Rep(i, n) for(int i = 1; i <= (int)(n); i++)
#define llrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define llRep(i, n) for(ll i = 1; i <= (ll)(n); i++)

using namespace std;

struct Point{
	int x,y;
};

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

bool connected[10][10];
bool visited[10];
int cnt=0;
int N,M,a,b;

bool isAllVisited(int N){
    Rep(i,N){
        if (visited[i]==false) return false;
    }
    return true;
}


void dfs(int now){
    if (isAllVisited(N)==true){
        cnt ++;
        return;
    }
    Rep(i,N){
        if(!connected[now][i]) continue;
        if (visited[i]) continue;
        visited[i] = true;
        dfs(i);
        visited[i] = false;
    }
    return;
}

int main(){
    cin >> N >> M;

    rep(i,10){
        rep(j,10){
            connected[i][j] = false;
        }
    }

    rep(i,M){
        cin >> a >> b;
        connected[a][b] = connected[b][a] = true;
    }

    visited[1] = true;
    dfs(1);
    cout << cnt << endl;

    return 0;
}
