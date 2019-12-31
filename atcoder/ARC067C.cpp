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

int main(){
    ll mod = 1e9+7;
    ll N;
    cin >> N;
    //素数の集合を用意
    vector<ll> prime = Eratosthenes(N);
    //Nまでの数に素数が何回登場するのかを、素数ごとに数える
    ll cnt[N+2];
    llrep(i,N+2){
        cnt[i] = 0;
    }
    llRep(i,N){
        llrep(j,prime.size()){
            if (prime[j] <= i){
                // cout << "aaa" << endl;
                if (i%prime[j]==0){
                    // cout << i << " % " << prime[j] << " = 0" << endl;
                    ll add=0;
                    ll i_ = i;
                    while(i_%prime[j]==0){
                        add++;
                        i_ /= prime[j];
                    }
                    cnt[prime[j]] += add;
                }
            }
        }
    }
    ll ans=1;
    // llRep(i,N){
    //     cout << "cnt[" << i <<"] = " << cnt[i] << endl;
    // }
    llRep(i,N){
        if (cnt[i] >= 1){
            ans *= (cnt[i]+1);
            ans %= mod;
            // cout << "ans = " << ans << endl;
        }
    }
    cout << ans << endl;

    return 0;
}
