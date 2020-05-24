# include <bits/stdc++.h>

using namespace std;

string dp[3002][3002];

int main(){
    string S, T;
    cin >> S >> T;
    for(int i=0; i<=S.length(); i++){
        dp[i][0] = "";
    }
    for(int j=0; j<=T.length(); j++){
        dp[0][j] = "";
    }

    for(int i=1; i<=S.length(); i++){
        for(int j=1; j<=T.length(); j++){
            if (S[i-1]==T[j-1]){
                dp[i][j] = dp[i-1][j-1] + S[i-1];
            }else{
                if (dp[i-1][j].length() > dp[i][j-1].length()){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    cout << dp[S.length()][T.length()] << endl;
    return 0;
}