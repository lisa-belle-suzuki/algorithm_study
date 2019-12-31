# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>
#include <numeric>

typedef long long int ll;

using namespace std;

int main() {
    ll N,K,h;
    cin >> N >> K;
    ll H[N+4];
    for (ll i=1; i<=N; i++){
        cin >> h;
        H[i] = h;
    }

    ll dp[N+4];//dp[i]:i番目までのコスト最小値
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(H[2]-H[1]);
    
    for (ll i=3; i<=N; i++){
        ll Min = 10000*N;
        ll Min_candidate;
        for(ll j=1; j<=min(K, i-1); j++){
            Min_candidate = dp[i-j] + abs(H[i]-H[i-j]);
            if (Min_candidate < Min) {
                Min = Min_candidate;
            }
        }
        // cout << "i = " << i << " " << Min << endl;
        dp[i] = Min;
    }

    cout << dp[N] << endl;

    return 0;
}
