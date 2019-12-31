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
int dist[52][52];
char maze[52][52];

int main(){


    rep(i,52){
        rep(j,52){
            dist[i][j] = -1;
        }
    }

    int H,W;
    cin >> H >> W;
    int cnt=0;
    rep(i,H){
		rep(j,W){
            cin >> maze[i][j];
			if (maze[i][j] == '.') cnt ++;
        }
    }

	queue<Point> Q;
    Point s = {0, 0};
	Q.push(s);
	dist[0][0] = 0;
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
    if (dist[H-1][W-1]==-1) cout << -1 << endl;
    else cout << cnt - (dist[H-1][W-1]+1) << endl;

    return 0;
}
