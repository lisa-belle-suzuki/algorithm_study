#include <bits/stdc++.h>

using namespace std;

double p[3002];
double dp[3002][3002];

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> p[i];
    }

    dp[0][0] = 1.0;
    dp[1][0] = 1 - p[1];
    dp[1][1] = p[1];
    for(int i=2; i<=N; i++){
        for(int j=0; j<=i; j++){
            if (j==0){
                dp[i][0] = dp[i-1][0] * (1 - p[i]);
            }else if (j==i){
                dp[i][j] = dp[i-1][j-1] * p[i];
            }else{
                dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
            }
        }
    }
    double ans = 0.0;
    for(int j=N/2 + 1; j<=N; j++){
        ans += dp[N][j];
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}