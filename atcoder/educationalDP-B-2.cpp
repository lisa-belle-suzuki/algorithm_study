# include<bits/stdc++.h>

using namespace std;

int H[100002];
int dp[100002];

int main(){
    int N, K;
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> H[i];
    }
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2; i<=N; i++){
        int minCost = INT_MAX;
        for(int j=1; j<=min(K, i-1); j++){
            if (dp[i-j] +  abs(H[i] - H[i-j]) < minCost){
                minCost = dp[i-j] +  abs(H[i] - H[i-j]);
            }
        }
        dp[i] = minCost;
    }
    cout << dp[N] << endl;
    return 0;
}