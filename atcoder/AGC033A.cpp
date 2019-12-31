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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int dist[1002][1002];
char maze[1002][1002];

int main(){

    rep(i,1002){
        rep(j,1002){
            dist[i][j] = -1;
        }
    }

    int H,W;
    cin >> H >> W;
    int cnt=0;
    rep(i,H){
		rep(j,W){
            cin >> maze[i][j];
        }
    }

	queue<Point> Q;
    rep(i,H){
        rep(j,W){
            if (maze[i][j]=='#'){
                Point s = {i, j};
                Q.push(s);
                dist[i][j] = 0;
            }
        }
    }

	while(!Q.empty()){
		Point now = Q.front();
		Q.pop();
		rep(i, 4){
			Point next = {now.x+dx[i],now.y+dy[i]};
            if( next.x < 0 || next.x >= H || next.y < 0 || next.y >= W ) continue;
			if( maze[next.x][next.y] == '#' ) continue; // 壁
			if( dist[next.x][next.y] != -1 ) continue; // visited
			dist[next.x][next.y] = dist[now.x][now.y] + 1;
			Q.push(next);
		}
	}
    int ans = 0;
    rep(i,H)rep(j,W){
        ans = max(ans, dist[i][j]);
    }
    cout << ans << endl;

    return 0;
}
