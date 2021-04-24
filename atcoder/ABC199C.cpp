#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int idx_list[400002];
ll N,Q,t,a,b,tmp;


int main(){
    string S;
    cin >> N;
    cin >> S;
    cin >> Q;
    for(ll i=0; i<2*N; i++){
        idx_list[i] = i;
    }
    int isReversed = -1; // 1のときisReversed, -1のときreverseでない
    for(ll i=0; i<Q; i++){
        cin >> t >> a >> b;
        a -= 1;
        b -= 1;
        if (t==1){
            if (isReversed==1){
                if (a >= N) a -= N;
                else a += N;
                if (b >= N) b -= N;
                else b += N;
            }
            tmp = idx_list[a];
            idx_list[a] = idx_list[b];
            idx_list[b] = tmp;
        }else{ // t == 2
            isReversed *= -1;
        }
    }
    if (isReversed==1){
        for(ll i=0; i<2*N; i++){
            if (i < N){
                cout << S[idx_list[i+N]];
            }else{
                cout << S[idx_list[i-N]];
            }
        }
        cout << "" << endl;
    }else{
        for(ll i=0; i<2*N; i++){
            cout << S[idx_list[i]];
        }
        cout << "" << endl;
    }


    return 0;
}