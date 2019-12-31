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
int dist[50][50];

int main(){
    rep(i,50){
		rep(j,50){
			dist[i][j] = -1;
        }
    }

    int R,C,sy,sx,gy,gx;
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;
    sy--; sx--;
    gy--; gx--;
    char maze[52][52];
    rep(i,R){
        rep(j,C){
            cin >> maze[i][j];
        }
    }

	queue<Point> Q;
    Point s = {sx, sy};
	Q.push(s);
	dist[sy][sx] = 0;
	while(!Q.empty()){
		Point now = Q.front();
		Q.pop();
		rep(i, 4){
			Point next = {now.x+dx[i],now.y+dy[i]};
			if( maze[next.y][next.x] == '#' ) continue; // 壁
			if( dist[next.y][next.x] != -1 ) continue; // visited
			dist[next.y][next.x] = dist[now.y][now.x] + 1;
			Q.push(next);
		}
	}
    cout << dist[gy][gx] << endl;

    return 0;
}
