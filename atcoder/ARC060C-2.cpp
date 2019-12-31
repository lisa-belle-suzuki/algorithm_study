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
    X.push_back(0);
    Sum.push_back(0);

    llrep(i,N){
        cin >> x;
        X.push_back(x);
        sum += x;
        Sum.push_back(sum);
    }

    // cout << "AA" << endl;

    // ll dp[N+5][N+5][2505];

    ll ***dp;
    dp = (ll ***)calloc(N+5, sizeof(ll **));
    for(ll i=0; i<N+5; i++){
        dp[i] = (ll **)calloc(N+5, sizeof(ll *));
        for(ll j=0; j<N+5; j++){
            dp[i][j] = (ll *)calloc(2505, sizeof(ll));
        }
    }

    // cout << "pp" << endl;


    llrep(i,N+2){
        llrep(j,N+2){
            llrep(k,sum+1){
                dp[i][j][k]=0;
            }
        }
    }

    // cout << "BB" << endl;


    llrep(i,N+1){
        llrep(j,i+1){
            llrep(k,Sum[i]+1){
                if (i==0 && j==0 && k==0) dp[i][j][k] = 1;
                if (i>=1 && j>=1 && k>=X[i]){
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-X[i]];
                }else if (i>=1 && k<X[i]){
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }

    // llrep(i,N+1){
    //     llrep(j,i+1){
    //         llrep(k,Sum[i]+1){
    //             cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;                
    //         }
    //     }
    // }

    ll cnt=0;
    llRep(i,sum/A){
        cnt += dp[N][i][A*i];
        // cout << "dp[" << N << "][" << i << "][" << A*i << "] = " << dp[N][i][A*i] << endl;
    }
    cout << cnt << endl;

    for(ll i=0; i<N+5; i++){
        for(ll j=0; j<N+5; j++){
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    return 0;
}
