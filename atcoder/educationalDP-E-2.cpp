# include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

ll dp[102][100002];

int main(){
    ll N, W, w, v;
    cin >> N >> W;
    dp[0][0] = 0;
    for(ll i=0; i<=101; i++){
        for(ll j=0; j<=1e5 + 1; j++){
            dp[i][j] = INT_MAX;
        }
    }
    for(ll i=1; i<=N; i++){
        cin >> w >> v;
        dp[i][0] = 0;
        if (i==1){
            for(ll j=1; j<=v; j++){
                if (w <= W){
                    dp[i][j] = w;
                }
            }
        }else{
            for(ll j=1; j<=1e5; j++){
                if (j < v){
                    dp[i][j] = min(dp[i-1][j], w);
                }
                if (j >= v && v <= 1e5){
                    if (dp[i-1][j-v]==INT_MAX){
                        continue;
                    }else{
                        dp[i][j] = min(dp[i-1][j-v] + w, dp[i-1][j]);
                    }
                }
            }
        }
    }

    ll max_value = -1;
    for(ll j=0; j<=1e5; j++){
        if (dp[N][j] <= W){
            max_value = j;
        }
    }
    cout << max_value << endl;
    return 0;
}