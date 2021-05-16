#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> A;
vector<ll> B;

int main(){
    ll N,a,b;
    cin >> N;
    for(ll i=0; i<N; i++){
        cin >> a;
        A.push_back(a);
    }
    for(ll i=0; i<N; i++){
        cin >> b;
        B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll cnt = 0;
    for(ll i=0; i<N; i++){
        cnt += abs(A[i]-B[i]);
    }

    cout << cnt << endl;

    return 0;
}