#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

const long long int INF = 1e14;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define Rep(i, n) for(int i = 1; i <= (int)(n); i++)
#define llrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define llRep(i, n) for(ll i = 1; i <= (ll)(n); i++)


using namespace std;

int main(){
    ll N;
    cin >> N;
    ll ans=1;
    llRep(i,N){
        ans *= i;
        if (ans > (ll)(pow(10,9)+7)) ans %= (ll)pow(10,9)+7;
    }
    cout << ans << endl;

    return 0;
}
