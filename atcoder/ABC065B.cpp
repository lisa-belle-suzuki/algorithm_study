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

int A[100002];

int howmany(int N){
    int now = 1;
    Rep(i,N){
        now = A[now];
        if (now==2) return i;
    }
    return -1;
}

int main(){
    int N,a,now;
    cin >> N;
    Rep(i,N){
        cin >> a;
        A[i] = a;
    }

    cout << howmany(N) << endl; return 0;
}
