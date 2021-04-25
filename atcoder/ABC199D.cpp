#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N,M,a,b;
vector<int> to[22];
int order[22];
bool visited[22];
ll ans=0;

void visit(int idx=0){
    for(int i=0; i<N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        order[idx] = i;
        visit(idx+1);
    }
    return;
}

void dfs(int colors[], int cur_idx_in_order=0){
    if (cur_idx_in_order==N){
        ans++;
        return;
    }
    // order[cur_idx_in_order]に繋がっている全ての隣接するノードについて、
    int cur = order[cur_idx_in_order];
    // 色の被りがないようにするにはどの色が使えるかを調べる
    bool canPaint[4] = {false, true, true, true};
    for(auto& adja: to[cur]){
        int adja_col = colors[adja];
        if (adja_col==0) continue;
        canPaint[adja_col] = false;
    }
    // 使える色全てについて、
    // 次のorderは何かを調べて、dfs
    for(int col=1; col<=3; col++){
        if (canPaint[col]==true){
            // 色を塗る
            colors[cur] = col;
            dfs(colors, cur_idx_in_order+1);
            colors[cur] = 0;
        }
    }

    return;
}

int main(){
    cin >> N >> M;
    for(ll i=0; i<M; i++){
        cin >> a >> b;
        a --; b --;
        // 隣接リスト
        to[a].push_back(b);
        to[b].push_back(a);
    }

    // 適当なノードからはじめて、orderに追加
    visit();
    // 各ノードについて3*(2^n)探索を行う
    int cols[22] = {};
    dfs(cols);

    cout << ans << endl;
    return 0;
}