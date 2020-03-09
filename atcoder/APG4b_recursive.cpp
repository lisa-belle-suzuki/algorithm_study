# include <bits/stdc++.h>

using namespace std;


int max_cnt = 0;
unordered_map<int, vector<int >> children;
void res(int i, int cnt){
    while(!children[i].empty()){
        int child = children[i].back();
        children[i].pop_back();
        res(child, cnt+1);
    }
    if (cnt > max_cnt) max_cnt = cnt;
    return;
}


int main(){
    int N,p;
    cin >> N;
    for(int i=1; i<N; i++){
        cin >> p;
        children[p].push_back(i);
    }
    res(0,0);
    cout << max_cnt << endl;

}