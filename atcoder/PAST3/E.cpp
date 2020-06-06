# include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> edge[201];
int color[201];

int main(){
    int N, Q, M, u, v, num, x, y;
    cin >> N >> M >> Q;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i=1; i<=N; i++){
        cin >> color[i];
        // cout << "color = " << color[i] << endl;
    }

    vector<int> output_num;
    for(int i=0; i<Q; i++){
        cin >> num;
        if (num==1){
            cin >> x;
            output_num.push_back(color[x]);
            for(int j=0; j<edge[x].size(); j++){
                color[edge[x][j]] = color[x];
            }
        }else{
            cin >> x >> y;
            output_num.push_back(color[x]);
            color[x] = y;
        }
    }
    for(int i=0; i<output_num.size(); i++){
        cout << output_num[i] << endl;
    }
    return 0;
}