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

    ll N,a,b,c;
    cin >> N;
    ll A[N+4], B[N+4], C[N+4];
    Rep(i,N) {
        cin >> a >> b >> c;
        A[i] = a;
        B[i] = b;
        C[i] = c;
    }
    ll dp[N+4][4];
    dp[1][0] = A[1];
    dp[1][1] = B[1];
    dp[1][2] = C[1];

    for(ll i=2; i<=N; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + A[i];
        dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + B[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + C[i];
    }

    cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;

    return 0;
}
