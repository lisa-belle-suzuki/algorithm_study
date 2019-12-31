# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>
#include <numeric>

typedef long long int ll;


using namespace std;

int main() {
    ll N, p;
    cin >> N;
    ll P[N+4], P_sum[N+4];
    P_sum[0] = 0;
    for (ll i=1; i<=N; i++){
        cin >> p;
        P_sum[i] = P_sum[i-1] + p;
        P[i] = p;
    }

    bool dp[N+4][10004];
    dp[0][0]=true;

    for (ll i=1; i<=N; i++){
        for (ll j=0; j<=P_sum[i]; j++){
            dp[i][j] = (dp[i-1][j] || dp[i-1][j-P[i]]);
        }
    }

    ll cnt=0;
    for(ll i=0; i<=P_sum[N]; i++){
        if (dp[N][i]){
            cnt ++;
        }
    }

    cout << cnt << endl;

    return 0;
}
