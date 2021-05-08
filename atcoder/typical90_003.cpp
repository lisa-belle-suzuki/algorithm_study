#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,a,b;
vector<ll> tree[100002];


pair<ll,ll> calc_farthest_node(ll a){
    // bfs
    vector<ll> distance(100002, -1);
    queue<pair<ll, ll>> que;
    pair<ll, ll> p = make_pair(a, 0);
    que.push(p);
    while (!que.empty()){
        pair<ll, ll> cur = que.front();
        que.pop();
        if (distance[cur.first] > 0) continue;
        distance[cur.first] = cur.second;
        for(auto elem : tree[cur.first]){
            if (distance[elem] > 0) continue;
            pair<ll, ll> p = make_pair(elem, cur.second+1);
            que.push(p);
        }
    }
    ll max_distance = -1;
    ll farthest = -1;
    for(ll i=1; i<=N; i++){
        if (i == a) continue;
        if (distance[i] > max_distance){
            max_distance = distance[i];
            farthest = i;
        }
    }
    p = make_pair(farthest, max_distance);
    return p;
}



int main(){
    cin >> N;
    //// 木構造を作る
    for(ll i=0; i<N-1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    //// 木の直径を調べる
    // ある頂点からの最短距離を各点に対して調べる(BFS)
    pair<ll,ll> farthest_node = calc_farthest_node(1);

    // 最も最短距離が遠い点Aから、最短距離が最も遠い点Bを調べる
    pair<ll,ll> farthest_from_A = calc_farthest_node(farthest_node.first);
    // AとBの最短距離が、木の直径
    cout << farthest_from_A.second+1 << endl;
    return 0;
}