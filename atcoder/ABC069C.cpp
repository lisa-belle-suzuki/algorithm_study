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
    ll N,a;
    cin >> N;
    ll cnt_odd=0,cnt_even=0, cnt_four=0;
    llrep(i,N){
        cin >> a;
        if (a%2==0){
            if (a%4==0) cnt_four ++;
            else cnt_even ++;
        }else{
            cnt_odd ++;
        }
    }
    if (cnt_even==0){
        if(cnt_odd==0) cout << "Yes" << endl;
        else if (cnt_four==0 && cnt_odd>0) cout << "No" << endl;
        else if(cnt_four - cnt_odd >= -1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        if (cnt_odd==0){//奇数がない
            if (cnt_four>0) cout << "Yes" << endl;
            else if (cnt_even>=2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{//奇数がある
            if (cnt_four==0 || cnt_four - cnt_odd < -1) cout << "No" << endl;
            else if (cnt_four - cnt_odd >= 0) cout << "Yes" << endl;
            // else if (cnt_even >= 2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
