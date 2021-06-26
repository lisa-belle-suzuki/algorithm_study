#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll A[1002],B[1002];

bool can_match(ll necessary, ll upper_bound){
    if (necessary > upper_bound) return false;
    return necessary%2 == upper_bound%2;
}

int main(){
    ll N,K,operations_num=0;
    cin>>N>>K;
    for(ll i=0; i<N; i++) cin >> A[i];
    for(ll i=0; i<N; i++) cin >> B[i];
    for(ll i=0; i<N; i++){
        operations_num += abs(A[i]-B[i]);
    }
    if (can_match(operations_num, K)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}