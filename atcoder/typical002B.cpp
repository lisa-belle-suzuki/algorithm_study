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

const long long int INF = 1e14;
typedef long long int ll;

using namespace std;

ll pow_mod(ll n, ll k, ll m){
    if (k==0){
        return 1;
    }else if (k%2==1){
        return (pow_mod(n, k-1, m) * n) % m;
    }else{
        ll t = pow_mod(n, k/2, m);
        return (t * t) % m;
    }
}

int main(){
    ll N,M,P;
    cin >> N >> M >> P;
    ll rest = N%M;
    ll ans = pow_mod(N, P, M);
    cout << ans << endl;

    return 0;
}
