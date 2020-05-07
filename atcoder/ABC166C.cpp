#include <bits/stdc++.h>

using namespace std;

bool haveOkashi[102];
int H[100002];
vector<int> road[100002];

int main(){
    int N, M, h, s,g, cnt=0, curH;
    cin >> N >> M;
    for(int i=1; i<N+1; i++){
        cin >> h;
        H[i] = h;
    }
    for(int i=0; i<M; i++){
        cin >> s >> g;
        road[s].push_back(g);
        road[g].push_back(s);
    }

    for(int i=1; i<N+1; i++){
        curH = H[i];
        bool isOK = true;
        for(int j=0; j<road[i].size(); j++){
            if ( curH <= H[road[i][j]] ){
                isOK = false;
            }
        }
        if (isOK){
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}