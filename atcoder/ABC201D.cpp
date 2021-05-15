#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;


ll H,W;
int A[2002][2002];
ll dp[2002][2002];


string who_wins(){
    for(ll i=H-1; i>=0; i--){
        for(ll j=W-1; j>=0; j--){
            if (i==H-1 && j==W-1) continue;
            if (i==H-1){
                dp[i][j] = -dp[i][j+1]+A[i][j+1];
            }else if (j==W-1){
                dp[i][j] = -dp[i+1][j]+A[i+1][j];
            }else{
                dp[i][j] = max(
                    -dp[i+1][j]+A[i+1][j],
                    -dp[i][j+1]+A[i][j+1]
                );
            }
        }
    }
    if (dp[0][0]>0) return  "Takahashi";
    else if(dp[0][0]==0) return "Draw";
    else return"Aoki";
}


int main(){
    char a;
    cin >> H >> W;
    for(ll i=0; i<H; i++){
        for(ll j=0; j<W; j++){
            cin >> a;
            if (a=='+') A[i][j] = 1;
            else A[i][j] = -1;
        }
    }
    cout << who_wins() << endl;
}
