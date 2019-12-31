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

using namespace std;

struct Point{
	int x,y;
};
char c[50][50];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int dist[50][50];
int main(){
	for(int i = 0 ; i < 50 ; i++)
		for(int j = 0 ; j < 50 ; j++)
			dist[i][j] = -1;

	int H,W;
	cin >> H >> W;
	int sx,sy,gx,gy;
	cin >> sy >> sx;
	cin >> gy >> gx;
	sy--,sx--;
	gy--,gx--;

	rep(i, H){
		rep(j, W){
			cin >> c[i][j];
        }
    }
	
	queue<Point> Q;
    Point s = {sx, sy};
	Q.push(s);
	dist[sy][sx] = 0;
	while(!Q.empty()){
		Point now = Q.front();
		Q.pop();
		for(int i = 0 ; i < 4 ; i++){
			Point next = {now.x+dx[i],now.y+dy[i]};
			if( c[next.y][next.x] == '#' ) continue; // 壁
			if( dist[next.y][next.x] != -1 ) continue; // visited
			dist[next.y][next.x] = dist[now.y][now.x] + 1;
			Q.push(next);
		}	
	}
	cout << dist[gy][gx] << endl;
}
