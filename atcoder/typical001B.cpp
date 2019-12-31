# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>
#include <numeric>

const long long int INF = 1e14;
typedef long long int ll;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)
#define Rep(i,n) for(ll i=1; i<=n; i++)
// #define orep(i,s,e) for(ll i=s; i<e; i++)
// #define oRep(i,s,e) for(ll i=s; i<=e; i++)

using namespace std;

ll par[100002];

ll root(ll x){
    if (par[x]==x) return x;
    else return par[x] = root(par[x]);
}

bool isUnited(ll x, ll y){
    if (root(x)==root(y)) return true;
    else return false;
}

void unite(ll x, ll y){
    ll rootx = root(x);
    ll rooty = root(y);

    if (rootx != rooty) par[rootx] = rooty;
}

int main() {
    ll N, Q, p,a,b;
    cin >> N >> Q;
    Rep(i, N){
        par[i] = i;//根ノードを初期化
    }

    ll p_array[Q+2], a_array[Q+2], b_array[Q+2];
    Rep(i, Q){
        cin >> p >> a >> b;
        p_array[i] = p;
        a_array[i] = a;
        b_array[i] = b;

    }
    Rep(i,Q){
        p = p_array[i];
        a = a_array[i];
        b = b_array[i];

        if (p == 0){
            //連結
            unite(a,b);
        }else{
            //判定
            if (isUnited(a,b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
