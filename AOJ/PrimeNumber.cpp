#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isPrime[1000000];

ll cnt_prime_number(ll num){
    // エラトステネスの篩
    for(ll i=1; i<=num; i++){
        isPrime[i] = true;
    }
    isPrime[1] = false;
    ll cnt = 0;
    for (ll i=2; i<=int(sqrt(num)); i++){
        for (ll j=2; j<=(num/i); j++){
            isPrime[i*j] = false;
        }
    }
    for (ll i=1; i<=num; i++){
        if (isPrime[i]) cnt ++;
    }
    return cnt;
}


int main(){
    ll n;
    while(1){
        cin >> n;
        if(std::cin.eof()) break;
        cout << cnt_prime_number(n) << endl;
    }
    return 0;
}