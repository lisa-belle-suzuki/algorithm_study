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

bool vector_finder(std::vector<int> vec, int number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
    }
  else { // 発見できなかったとき
    return false;
    }
}

int main(){
    ll D,G;
    cin >> D >> G;
    ll P[D+2], C[D+2];
    llrep(i,D){
        cin >> P[i] >> C[i];
    }

    ll minimum = 1000;

    // cout << "---------------------" << endl;
    int n=D;
    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit)
    {
        // cout << "bit = " << bit << endl;
        ll sum=0;
        ll cnt=0;
        // bit の表す集合を求める
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // i が bit に入るかどうか
                S.push_back(i);
                sum += (100 * (i+1) * P[i] + C[i]);
                cnt += P[i];
            }
        }
        // cout << "sum = " << sum << endl;
        // cout << "cnt = " << cnt << endl;


        if (sum < G){
            ll rest = G - sum;
            for(int i=D; i>0; i--){
                // cout << "bbb" << endl;
                if (rest > 0){
                    if (!vector_finder(S, i-1)){
                        if (rest - (P[i-1]-1)*(100*i) < 0){//残りがP[i-1]-1個以下ですむ
                            if (rest%(100*i)==0){
                                cnt += (rest/(100*i));
                                rest -= 100*i*(rest/(100*i));
                            }else{
                                cnt += (rest/(100*i)) + 1;
                                rest -= 100*i*(rest/(100*i)+1);
                            }
                        }else{
                            cnt += (P[i-1]-1);
                            rest -= (P[i-1]-1)*(100*i);
                        }
                    }
                }
            }
            if (rest > 0) cnt=1000;
        }
        if (cnt < minimum) minimum = cnt;
        // cout << "cnt = " << cnt << endl;
        // cout << "minimum = " << minimum << endl;
        // cout << "---------------------" << endl;
    }

    cout << minimum << endl;

    return 0;
}
