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

bool visited[100002];
int steps[100002];
vector<vector<pair<ll, ll> > > edge(100002);
ll N,u,v,w;

void dfs(ll prev, ll cur, ll cnt, ll add){
    // cntを増やす
    visited[cur] = true;
    cnt += add;
    steps[cur] = cnt;
    //edgeで繋がっているかつvisitedでないノードにいく
    llrep(i,edge[cur].size()){
        ll next = edge[cur][i].first;
        if (!visited[next]){
            dfs(cur, next, cnt, edge[cur][i].second);
        }
    }
    return;
}
int main(){
    ll H,W,A,B;
    cin >> H >> W >> A >> B;
    ll ans=0;
    ll fact[H+W+2];
    ll mod = (1e9+7);

    fact[0] = 1;
    for(ll i=1; i<=H+W; i++){
        ll Fact = fact[i-1] * i;
        if (Fact > mod)fact[i] = Fact%mod;
        else fact[i] = Fact;
    }

    for(ll i=B; i<W; i++){
        //デバッグ用
        // if (fact[i]==0) cout << "aaa" << endl;
        // if (fact[H-A-1]==0) cout << "PPPP" << endl;
        // if (fact[A-1]==0 || fact[W-i-1]==0) cout << "aaa" << endl;

        ll a = ( ( fact[i+H-A-1] / fact[i]) / fact[H-A-1] );//combination(i,H-A-1)
        ll b = ( ( fact[A+W-i-2] / (fact[A-1])) / fact[W-i-1] );//combination(A-1,W-i-1)
        ans += (a * b)%mod;
        ans %= (ll)mod;
    }
    cout << ans << endl;

    return 0;
}


