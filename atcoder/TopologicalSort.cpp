# include<bits/stdc++.h>

using namespace std;

bool Connected[17][17];
vector<int> task_order;
bool visited[17];
int N,M,x,y;

void dfs(int cur_node){
    visited[cur_node] = true;
    for (int i=1; i<=N; i++){
        if (Connected[cur_node][i]==true && visited[i]==false){
            dfs(i);
        }
    }
    task_order.push_back(cur_node);

    for(int i=1; i<=N; i++){
        if (visited[i]==false){
            dfs(i);
        }
    }
    return;
}

int main(){
    cin >> N >> M;
    // 隣接グラフ
    for(int i=0; i<M; i++){
        cin >> x >> y;
        Connected[x][y] = true;
    }
    // トポロジカルソート
    dfs(1);

    while(!task_order.empty()){
        cout << task_order.back() << endl;
        task_order.pop_back();
    }
    return 0;
}