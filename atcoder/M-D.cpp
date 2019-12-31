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

void chmax(int prev_max, int new_max){
    if (new_max > prev_max){
        prev_max = new_max;
    }
    return;
}

void chmin(int prev_min, int new_min){
    if (new_min > prev_min){
        prev_min = new_min;
    }
    return;
}

// 二分探索
// llrep(i,N){
//     b = B[i];
//     auto cntA = lower_bound(A.begin(), A.end(), b);//イテレータなのでそのままllに変換とかはできない
//     auto cntC = upper_bound(C.begin(), C.end(), b);
//     ll cntA_ll = distance(A.begin(), cntA);
//     ll cntC_ll = C.size() - distance(C.begin(), cntC);
//     cnt += (cntA_ll * cntC_ll);
// }

bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first > b.first;
    }
}

vector<pair<int , int> > node_cnt;
vector<int> C;
int d[10002];
int cnt[10002];
int A[10002];
int B[10002];


int main(){
    int N,a,b,c;
    cin >> N;
    rep(i,N-1){
        cin >> a >> b;
        cnt[a] ++;
        cnt[b] ++;
        A[i]=a;
        B[i]=b;
    }
    rep(i,N){
        if (cnt[i] > 0){
            node_cnt.push_back(make_pair(i, cnt[i]));
        }
    }
    rep(i,N){
        cin >> c;
        C.push_back(c);
    }
    sort(node_cnt.begin(), node_cnt.end(), compare_by_b);
    sort(C.begin(), C.end(), greater<int>());

    rep(i,N){
        d[node_cnt[i].first] = C[i];
    }
    ll M=0;
    rep(i,N-1){
        // cout << "d[A[i]] = " << d[A[i]] << endl;
        // cout << "d[B[i]] = " << d[B[i]] << endl;

        cout << "+ = " << min(d[A[i]] , d[B[i]]) << endl;
        M += min(d[A[i]] , d[B[i]]);
    }
    cout << M << endl;
    cout << d[0];
    Rep(i,N-1) cout << " " << d[i];
    cout << "" << endl;

    return 0;
}
