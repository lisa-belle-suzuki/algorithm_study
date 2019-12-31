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


vector<ll> A;
// priority_queue<ll, vector<ll>, greater<ll> > queueA;

vector<pair<ll, ll> > B_C;

bool compare_by_second(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first > b.first;
    }
}

int main(){
    ll N,M,a,b,c;
    cin >> N >> M;
    ll sum=0;
    llrep(i,N){
        cin >> a;
        // queueA.push(a);
        A.push_back(a);
        sum += a;
    }
    sort(A.begin(), A.end());
    // llrep(i,A.size()){
    //     cout <<A[i] << endl;
    // }

    llrep(i,M){
        cin >> b >> c;
        B_C.push_back(make_pair(b,c));
    //     llrep(j,b){
    //         if (c > queueA.top()){
    //             sum += (c - queueA.top());
    //             queueA.pop();
    //             queueA.push(c);
    //         }
    //     }
    }
    sort(B_C.begin(), B_C.end(), compare_by_second);

    ll change=0,cnt;
    llrep(i,M){
        b = B_C[i].first;
        c = B_C[i].second;
        if (c <= A[change]) break;
        if (change >= N) break;
        cnt=0;
        llrep(j,b){
            if (change + j < N && c > A[change + j]){
                // cout << "erase " << A[change + j] << " & add "<< c << endl;
                sum += (c - A[change + j]);
                A[change + j] = c;
                cnt++;
                // queueA.pop();
                // queueA.push(c);
            }
        }
        change += cnt;
    }

    cout << sum << endl;
    return 0;
}
