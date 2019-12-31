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
int cnt=0;
int N,M,a,b;

bool isOk(vector<int> v){
    rep(i, v.size()-1){
        if (!connected[v[i]][v[i+1]]) return false;
    }
    return true;
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

    vector<int> v(N);
    iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
    do {
        if (v[0] != 1) continue;
        if (isOk(v)){
            // rep(i,v.size()){
            //     cout << v[i] << " ";
            // }
            cnt ++;
            // cout << "" << endl;
        }
    } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成

    cout << cnt << endl;

    return 0;
}
