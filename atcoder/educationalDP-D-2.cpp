# include<bits/stdc++.h>

using namespace std;

typedef long long int ll;


ll dp[102][100002];


int main(){
    ll N,W, w,v;
    cin >> N >> W;
    for(int i=1; i<=N; i++){
        cin >> w >> v;
        for(int j=0; j<=W; j++){
            if ((j-w)>=0){
                dp[i][j] = max(dp[i-1][j-w] + v, dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // for(int i=0; i<=N; i++){
    //     cout << dp[i][W] << endl;
    // }
    cout << dp[N][W] << endl;
    return 0;
}