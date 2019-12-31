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

char alphabet[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
};


int main(){
    ll A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;

    //water
    vector<ll> x,y;
    llrep(i,F/(100*A)+1){
        llrep(j,F/(100*B)+1){
            x.push_back(100*A*i + 100*B*j);
        }
    }


    //sugar
    llrep(i,F/C+1){
        llrep(j,F/D+1){
            y.push_back(C*i + D*j);
        }
    }

    float max_ratio = 0;
    ll max_water=-1;
    ll max_sugar=-1;

    llrep(i,x.size()){
        llrep(j,y.size()){
            if (x[i] + y[j] > F) continue;
            if ( ( E * x[i] ) >=  (100 * y[j]) ){
                if ( y[j] * 100 >= (x[i] * max_ratio) ){
                    max_water = x[i];
                    max_sugar = y[j];
                    if (max_water > 0){
                        max_ratio = (float)(max_sugar * 100) / max_water;
                    }
                }
            }
        }
    }


    cout << max_water+max_sugar << " " << max_sugar << endl;

    return 0;
}
