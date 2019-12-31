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
    string Str;
    cin >> Str;

    int n = Str.length()-1;
    ll sum=0;
    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit) {
        /* bit で表される集合の処理を書く */
        /* きちんとできていることを確認してみる */
        // bit の表す集合を求める
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // i が bit に入るかどうか
                S.push_back(i);
            }
        }

        // bit の表す集合の出力
        ll start=0;
        for (int i = 0; i < (int)S.size(); ++i) {
            ll left = stoll(Str.substr(start, S[i]-start+1));
            sum += left;
            start = S[i]+1;
        }
        sum += stoll(Str.substr(start, Str.length()-start)) ;
    }
    
    cout << sum << endl;

    return 0;
}
