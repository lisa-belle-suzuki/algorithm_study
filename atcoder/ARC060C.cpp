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

const long long int INF = 1e9;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define Rep(i, n) for(int i = 1; i <= (int)(n); i++)
#define llrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define llRep(i, n) for(ll i = 1; i <= (ll)(n); i++)

using namespace std;

struct Point{
	int x,y;
};

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
    ll N,A, x,sum=0;
    cin >> N >> A;
    vector<ll> X,Sum;
    llrep(i,N){
        cin >> x;
        X.push_back(x);
        sum += x;
        Sum.push_back(sum);
    }

    ll dp[N+2][N+2][2502];

    llrep(i,N+2){
        llrep(j,N+2){
            llrep(k,2502){
                dp[i][j][k]=0;
            }
        }
    }


    dp[0][0][0] = 1;
    dp[0][1][X[0]] = 1;

    llRep(i,N-1){
        llrep(j,i+2){
            llrep(k,Sum[i]+1){
                if (j>=1 && k>=X[i]){
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-X[i]];
                }else if (k<X[i]){
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    ll cnt=0;
    llRep(i,sum/A){
        cnt += dp[N-1][i][A*i];
    }
    cout << cnt << endl;
    return 0;
}
