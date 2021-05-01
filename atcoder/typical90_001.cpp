#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[100002];
ll l,r,c,N,K,L;

bool canDivide(ll division_length, ll youkan_length){
    ll prev = 0, cut = 0;
    for(ll i=0; i<N; i++){
        if (A[i] - prev >= division_length){
            prev = A[i];
            cut ++;
        }
        if (cut == K){
            break;
        }
    }
    if (youkan_length - prev < division_length){
        // cout << "L - prev < youkan_length" << endl;
        return false;
    }
    if (cut >= K) return true;
    else return false;
}


int main(){
    cin >> N >> L;
    cin >> K;
    for(ll i=0; i<N; i++){
        cin >> A[i];
    }
    // 長さxのようかんをK+1個に分割できる最大のxを二分探索
    l = 1;
    r = L;
    while (l<=r){
        c = (l+r)/2;
        // cout << "--------------" << endl;
        // cout << "c = " << c << endl;
        if (canDivide(c, L)){
            // cout << "yes" << endl;
            l = c + 1;
        }else{
            // cout << "no" << endl;
            r = c - 1;
        }
    }
    cout << r << endl;
    return 0;
}
