#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> A;

int main(){
    ll N,a;
    cin>>N;
    for(int i=0;i<3;i++){
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end(), greater<ll>());
    ll cnt = 1000000000;
    if (A[0]==1){
        cout << N << endl;
        return 0;
    }
    for(ll i=N/A[0]; i>=0; i--){
        for(ll j=(N-A[0]*i)/A[1]; j>=0; j--){
            ll k=(N-A[0]*i-A[1]*j)/A[2];
            if (A[0]*i+A[1]*j+A[2]*k < N) continue;
            cnt = min(cnt, i+j+k);
        }
    }
    cout << cnt << endl;

    return 0;
}