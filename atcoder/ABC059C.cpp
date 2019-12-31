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

char alphabet[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
};

int main(){
    ll n;
    cin >> n;
    ll sum[n+2];
    ll A[n+2];
    // rep(i,n+2){

    // }
    llRep(i,n){
        cin >> A[i];
    }
    sum[0] = 0;
    // sum[1] = A[1];
    //+,-,+,...
    ll cnt=0;
    for(ll i=1; i<=n; i++){
        sum[i] = sum[i-1] + A[i];
        if (i%2==0){//-
            if(sum[i]>-1){
                ll new_sum = -1;
                cnt += abs(new_sum - sum[i]);
                sum[i] = new_sum;
            }
        }else{//+
            if (sum[i]<1){
                ll new_sum = 1;
                cnt += abs(new_sum - sum[i]);
                sum[i] = new_sum;
            }
        }
    }
    
    //-,+,-,...
    ll cnt2 = 0;
    for(ll i=1; i<=n; i++){
        sum[i] = sum[i-1] + A[i];
        if (i%2==1){//-
            if(sum[i]>-1){
                ll new_sum = -1;
                cnt2 += abs(new_sum - sum[i]);
                sum[i] = new_sum;
            }
        }else{//+
            if (sum[i]<1){
                ll new_sum = 1;
                cnt2 += abs(new_sum - sum[i]);
                sum[i] = new_sum;
            }
        }
    }
    cout << min(cnt,cnt2) << endl;
    return 0;
}
