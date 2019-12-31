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

bool vector_finder(std::vector<ll> vec, ll number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
    }
  else { // 発見できなかったとき
    return false;
    }
}

ll factorial(ll N){
    ll ans = 1;
    llRep(i,N){
        ans *= i;
    }
    return ans;
}

vector<ll> Eratosthenes(ll N){
    bool arr[N+1];
    //initialization
    arr[0] = false;
    arr[1] = false;
	for(ll i = 2; i < N+1; i++){
		arr[i] = true;
	}
    //eratosthenes
	for(ll i = 2; i <= sqrt(N); i++){
		if(arr[i]){
			for(ll j = 0; i * (j + 2) <= N; j++){
				arr[i *(j + 2)] = false;//not prime number
			}
		}
	}
    vector<ll> prime;
    llRep(i,N){
        if (arr[i]==true){
            prime.push_back(i);
        }
    }
    return prime;
}

char alphabet[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
};

int main(){
    int N;
    cin >> N;
    bool dp[N+2][10002];
    int s[N+2], sum[N+2];
    rep(i,N+2){
        rep(j,10002){
            dp[i][j]=false;
        }
    }
    sum[0]=0;
    Rep(i,N){
        cin >> s[i];
        sum[i] = sum[i-1] + s[i];
    }

    dp[0][0] = true;
    Rep(i,N){
        rep(j,sum[i]+1){
            // if (i>=1){
                if (j >= (s[i])){
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-s[i]]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            // }
        }
    }

    int max = 0;
    rep(i,sum[N]+1){
        if (dp[N][i]==true && i%10!=0){
            max = i;
        }
    }
    cout << max << endl;

    return 0;
}
