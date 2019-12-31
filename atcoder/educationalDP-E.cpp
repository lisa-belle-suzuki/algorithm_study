# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>
#include <numeric>

const long long int INF = 1e14;
typedef long long int ll;
#define rep(i,n) for(ll i=0; i<n; i++)
#define Rep(i,n) for(ll i=1; i<=n; i++)


using namespace std;

int main() {
    ll N, W, v, w, vsum=0;
    cin >> N >> W;
    ll vi[N+4], wi[N+4], vsumi[N+4];
    Rep(i,N){
        cin >> w >> v;
        vi[i] = v;
        wi[i] = w;
        vsum += v;
        vsumi[i] = vsum;
    }

    ll dp[N+4][vsum+4];
    dp[1][0] = 0;
    Rep(i, vsum){
        dp[1][i] = INF;
    }
    dp[1][vi[1]] = wi[1];

    for(ll i=2; i<=N; i++){
        rep(j,vsum+1){
            if (j >= vi[i]){
                dp[i][j] = min( dp[i-1][j], dp[i-1][j-vi[i]] + wi[i] );
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // Rep(i,N){
    //     rep(j,vsum+1){
    //         cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
    //     }
    // }

    ll maxval = 0;
    rep(i, vsum+1){
        if (dp[N][i] <= W){
            // cout << "i = " << i << ": " << maxval << endl;
            maxval = i;
        }
    }
    cout << maxval << endl;
    
    return 0;
}
