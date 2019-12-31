# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>
#include <numeric>

typedef long long int ll;
#define rep(i,n) for(ll i=0; i<n; i++)
#define Rep(i,n) for(ll i=1; i<=n; i++)


using namespace std;

int main() {

    ll N,W,a,b,c, wi, vi;
    cin >> N >> W;
    ll w[N+4], v[N+4];
    Rep(i,N){
        cin >> wi >> vi;
        w[i] = wi;
        v[i] = vi;
    }

    ll dp[N+4][W+4];
    rep(i,W+1){
        dp[0][i] = 0;
    }

    cout << "aaaa" << endl;


    Rep(i,N){
        rep(j,W+1){
            if (w[i] <= j){
                dp[i][j] = max (dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // Rep(i,N){
    //     cout << dp[i][W] << endl;
    // }

    cout << dp[N][W] << endl;

    return 0;
}
