#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N, m=0, M=1001,a,b;
    cin >> N;

    for(ll i=0; i<N; i++){
        cin >> a;
        m = max(m, a);
    }
    for(ll i=0; i<N; i++){
        cin >> b;
        M = min(M, b);
    }
    if (m==M) cout << 1 << endl;
    else if(m>M) cout << 0 << endl;
    else cout << (M-m+1) << endl;
    return 0;
}