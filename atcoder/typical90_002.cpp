#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<string> ans;

void solve(string cur, int left_cnt, int right_cnt){
    if (cur.length() == N){
        if (left_cnt == right_cnt) ans.push_back(cur);
        return;
    }
    if (left_cnt > right_cnt) solve(cur+")", left_cnt, right_cnt+1);
    solve(cur+"(", left_cnt+1, right_cnt);
    return;
}


int main(){
    cin >> N;
    if (N%2 == 1){
        return 0;
    }
    // 全探索
    solve("",0,0);
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}