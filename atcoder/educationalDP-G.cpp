# include <bits/stdc++.h>

using namespace std;

bool visited[100002];
int dp[100002];

bool graph[100002][100002];

int N, M ,x, y;

int solve(int i){
    if (visited[i]) return dp[i];
    int longest = 0;
    for(int j=1; j<=N; j++){
        if (graph[i][j]==true){
            if (visited[j]==true){
                if (longest < dp[j] + 1) longest = dp[j];
            }else{
                int candid = solve(j);
                if (longest < candid + 1) longest = candid + 1;
            }
        }
    }
    dp[i] = longest;
    return longest;
}


int main(){
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> x >> y;
        graph[x][y] = true;
    }

    int longest = 0, candid;
    for(int i=1; i<=N; i++){
        int candid = solve(i);
        // cout << "i = " << i << ": candid = " << candid << endl;
        if (candid > longest) longest = candid;
    }
    cout << longest << endl;
    return 0;
}