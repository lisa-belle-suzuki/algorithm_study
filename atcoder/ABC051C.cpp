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

int main(){
    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    ll x = abs(sx - tx);
    ll y = abs(sy - ty);
    // cout << "x = " << x;
    // cout << "y = " << y;


    rep(i,y) cout << 'U';
    rep(i,x) cout << 'R';

    rep(i,y) cout << 'D';
    rep(i,x) cout << 'L';

    cout << 'L';
    rep(i,y+1) cout << 'U';
    rep(i,x+1) cout << 'R';
    cout << 'D';

    cout << 'R';
    rep(i,y+1) cout << 'D';
    rep(i,x+1) cout << 'L';
    cout << 'U';
    
    cout << "" << endl;
    return 0;
}
