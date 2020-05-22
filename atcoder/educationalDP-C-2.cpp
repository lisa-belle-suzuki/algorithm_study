# include<bits/stdc++.h>

using namespace std;

int dp[100002][3];

int main(){
    int a,b,c,N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> a >> b >> c;
        if (i==1){
            dp[1][0] = a;
            dp[1][1] = b;
            dp[1][2] = c;
        }else{
            dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = b + max(dp[i-1][2], dp[i-1][0]);
            dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << endl;
    return 0;
}