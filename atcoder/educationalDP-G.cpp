# include <bits/stdc++.h>

using namespace std;

bool visited[100002];
int dp[100002];

vector<int> graph[100002];

int N, M ,x, y;

int solve(int i){
    if (visited[i]) return dp[i];
    int longest = 0;
    vector<int> connected_list = graph[i];
    // cout  << "i = " << i << ": connected_list.size() = " << connected_list.size() << endl;
    for(int j=0; j<connected_list.size(); j++){
        int connected = connected_list[j];
        if (visited[connected]==true){
            if (longest < dp[connected] + 1) longest = dp[connected] + 1;
        }else{
            int candid = solve(connected);
            if (longest < candid + 1) longest = candid + 1;
        }
    }
    dp[i] = longest;
    visited[i] = true;
    return longest;
}


int main(){
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i=1; i<=N; i++){
        visited[i] = false;
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