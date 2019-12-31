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

char plusminus(bool plus){
    if (plus) return '+';
    else return '-';
}

int main(){
    string S;
    cin >> S;
    int A = stoi(S)/1000;
    int B = (stoi(S)/100)%10;
    int C = (stoi(S)/10)%10;
    int D = stoi(S)%10;

    int bcd[] = {B,C,D};

    int n = 3;

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit)
    {
        /* bit で表される集合の処理を書く */

        /* きちんとできていることを確認してみる */
        // bit の表す集合を求める
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // i が bit に入るかどうか
                S.push_back(i);
            }
        }

        int ans = A;
        for(int i=0; i<3; i++){
            if (vector_finder(S, i)){
                ans += bcd[i];
            }else{
                ans -= bcd[i];
            }
        }
        // cout << ans << endl;
        if (ans==7){
            cout << A;
            cout << plusminus(vector_finder(S, 0));
            cout << B;
            cout << plusminus(vector_finder(S, 1));
            cout << C;
            cout << plusminus(vector_finder(S, 2));
            cout << D;
            cout << "=7" << endl;
            return 0;
        }
    }

    return 0;
}
