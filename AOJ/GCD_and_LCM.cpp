#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll m, ll n){
    while (1){
        if (m % n == 0) return n;
        if (n % m == 0) return m;
        if (m > n) m %= n;
        else n %= m;
    }
    return -1;
}

ll lcm(ll m, ll n, ll GCD){
    ll q_m = m / GCD;
    ll q_n = n / GCD;
    return GCD * q_m * q_n;
}


int main(){
    ll a,b;
    while (1){
        cin >> a >> b;
        if(std::cin.eof()) break;
        ll GCD = gcd(a,b);
        cout << GCD << " " << lcm(a,b,GCD) << endl;
    }
    return 0;
}