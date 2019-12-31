#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <locale>
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

ll extended_factorial(ll N){
    ll ans = 1;
    llRep(i,N){
        ans *= i;
        ans %= (ll)(1e9+7);
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

ll gcd(ll a, ll b){
    ll temp;
	while (a % b != 0){
		temp = b;
		b = a % b;
		a = temp;
	}
	return b;
}

ll lcm(ll a, ll b){
  return a * b / gcd(a,b);
}

char alphabet[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
};

ll digit__(ll num){
    ll cnt=1;
    while(num > 10){
        cnt ++;
        num /= 10;
    }
    return cnt;
}

int main(){
    ll A,B,X;
    cin >> A >> B >> X;
    ll N_max = X / A;
    // 二分探索
        // ll rest = X-A*n;
        // rest >= B*digit__(n))
    if (X >= A * 1e9 + B * digit__(1e9)){
        cout << 1000000000 << endl;
        return 0;
    }

    ll prev_max = 1000000000;
    ll prev_min = 0;
    while(1){
        ll cur = (prev_min + prev_max) / 2;
        if (X >= A * cur + B * digit__(cur)){
            prev_min = cur;
        }else{
            prev_max = cur;
        }
        if (prev_max == 0){
            cout << 0 << endl;
            return 0;
        }else if (prev_min + 1 = prev_max ){
            cout << prev_min << endl;
            return 0;
        }
    }
    

}
