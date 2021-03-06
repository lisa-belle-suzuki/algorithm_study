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

char alphabet[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
};

// 二分探索
// llrep(i,N){
//     b = B[i];
//     auto cntA = lower_bound(A.begin(), A.end(), b);//イテレータなのでそのままllに変換とかはできない
//     auto cntC = upper_bound(C.begin(), C.end(), b);
//     ll cntA_ll = distance(A.begin(), cntA);
//     ll cntC_ll = C.size() - distance(C.begin(), cntC);
//     cnt += (cntA_ll * cntC_ll);
// }

// ll gcd(ll a, ll b){
//     if (a%b==0) return b;
//     else if (b%a==0) return a;
//     else if (a > b) return gcd(a%b, b);
//     else return gcd(a, b%a);
// }

// ll ans(ll a, ll b){
//     if (a==b) return -1;
//     ll diff = abs(a-b);
//     if (diff==1) return 1;
//     else return diff;
// }

ll digit_sum(ll b, ll n){
    ll ans=0,add;
    while(n>0){
        // cout << "n = " << n << endl;
        add = n%b;
        // cout << "add = " << add << endl;
        ans += add;
        n /= b;
    }
    // cout << "hoge" << endl;
    return ans;
}

int main(){
    ll n,s;
    cin >> n;
    cin >> s;
    ll diff = abs(n-s);
    // cout << "diff = " << diff << endl;
    if (n==s){
        cout << n+1 << endl;
        return 0;
    }
    ll min_ans = 1e11+2;
    for(ll b=1; b*b<=diff; b++){
        // cout << "bbbb" << endl;
        if (diff%b==0){
            if (digit_sum(b+1,n)==s){
                if (b+1 < min_ans){
                    min_ans = b+1;
                }
            }else if (digit_sum((diff/b)+1,n)==s){
                if ((diff/b)+1 < min_ans){
                    min_ans = (diff/b)+1;
                }
            }
        }
    }
    if (min_ans == 1e11+2)  cout << -1 << endl;
    else cout << min_ans << endl;
    return 0;
}
