#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt;
set<int> st;

int tgt,ans;

void make_n_combi(int sum, int cnt){
    if (cnt == 4){
        if (sum == tgt){
            ans ++;
        }
        return;
    }
    for(int i=0; i<10; i++){
        make_n_combi(sum+i, cnt+1);
    }
    return;
}


int main(){
    int n;
    while(1){
        cin >> tgt;
        ans = 0;
        if(std::cin.eof()) break;
        make_n_combi(0, 0);
        cout << ans << endl;
    }
    return 0;
}