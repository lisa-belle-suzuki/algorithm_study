#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll C[100002],P[100002],L[100002],R[100002],sum1[100002],sum2[100002];

ll calc_score(ll class_num, ll l, ll r){
    if (class_num==1) return sum1[r]-sum1[l-1];
    else return sum2[r]-sum2[l-1];
}

int main(){
    ll N,Q,l,r;
    cin >> N;
    for(ll i=1; i<=N; i++){
        cin >> C[i] >> P[i];
    }
    // 累積和を計算しておく
    for(ll i=1; i<=N; i++){
        if (C[i]==1){
            sum1[i] = sum1[i-1]+P[i];
            sum2[i] = sum2[i-1];
        }else{
            sum1[i] = sum1[i-1];
            sum2[i] = sum2[i-1]+P[i];
        }
    }
    cin >> Q;
    for(ll i=0; i<Q; i++){
        cin >> l >> r;
        L[i] = l; R[i] = r;
    }
    for(ll i=0; i<Q; i++){
        cout << calc_score(1,L[i],R[i])<<" " << calc_score(2,L[i],R[i]) << endl;
    }
    return 0;
}