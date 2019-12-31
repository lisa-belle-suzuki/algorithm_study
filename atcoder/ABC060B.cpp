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

bool yes(int A, int B, int C){
    Rep(i,B){
        if ((A*i) % B==C){
            return true;
        }
    }
    return false;
}

using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;

    if (yes(A,B,C)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
