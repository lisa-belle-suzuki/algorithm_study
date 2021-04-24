#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int tgt,ans,n;

void make_n_combi(int sum, int cnt, int prev){
    if (cnt == n){
        if (sum == tgt){
            ans ++;
        }
        return;
    }
    for(int i=prev+1; i<10; i++){
        make_n_combi(sum+i, cnt+1, i);
    }
    return;
}


int main(){
    while(1){
        cin >> n >> tgt;
        ans = 0;
        if(n==0 && tgt==0) break;
        make_n_combi(0, 0, -1);
        cout << ans << endl;
    }
    return 0;
}