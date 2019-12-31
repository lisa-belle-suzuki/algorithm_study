# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>
#include <numeric>

typedef long long int ll;

using namespace std;

int main() {
    ll N, h;
    cin >> N;
    ll dp[N+4], H[N+4];
    for (ll i=1; i<=N; i++){
        cin >> h;
        H[i] = h;
    }

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(H[2]-H[1]);

    for (ll i=3; i<=N; i++){
        dp[i] = min(dp[i-1] + abs(H[i] - H[i-1]),
                    dp[i-2] + abs(H[i] - H[i-2]));
    }

    // for (ll i=0; i<=N; i++){
    //     cout << "i = " << i << " " << dp[i] << endl;
    // }

    cout << dp[N] << endl;

    return 0;
}
