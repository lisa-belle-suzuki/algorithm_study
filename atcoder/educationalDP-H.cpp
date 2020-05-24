# include <bits/stdc++.h>

typedef long long int ll;
using namespace std;

char maze[1002][1002];
ll dp[1002][1002];
ll divide = 1e9 + 7;

int main(){
    int H, W;
    cin >> H >> W;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> maze[i][j];
            dp[i][j] = 0;
        }
    }


    dp[0][0] = 1;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if (i==0){
                if (maze[0][j-1]=='.'){
                    dp[0][j] += dp[0][j-1];
                    dp[0][j] %= divide;
                }
            }else if (j==0){
                if (maze[i-1][0]=='.'){
                    dp[i][0] += dp[i-1][0];
                    dp[i][0] %= divide;
                }
            }else{
                if (maze[i-1][j]=='.'){
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= divide;
                }
                if (maze[i][j-1]=='.'){
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= divide;
                }
            }
        }
    }

    cout << dp[H-1][W-1] % divide << endl;
    return 0;
}