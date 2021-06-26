#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll gcd_pair(ll x, ll y){
    if (x < y) return gcd_pair(y, x);
    if (x % y == 0) return y;
    return gcd_pair(x%y, y);
}

ll gcd(ll x, ll y, ll z){
    return gcd_pair(
        gcd_pair(x, y),
        gcd_pair(x, z)
    );
}

int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll GCD = gcd(a,b,c);
    ll a_cut = a/GCD;
    ll b_cut = b/GCD;
    ll c_cut = c/GCD;
    cout << a_cut-1+b_cut-1+c_cut-1 << endl;
    return 0;
}