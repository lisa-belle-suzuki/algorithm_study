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
    ll H,W;
    vector<ll> min_cands;
    cin >> H >> W;

    // どちらかの辺が3で割り切れる場合
    if (H%3==0 || W%3==0){
        cout << 0 << endl;
        return 0;
    }

    // 横を割ってみる
    ll best=INF;
    ll best_w;
    llrep(i,W){
        if (abs(H*i - (float)(H*W/3.0)) < best){
            best = abs(H*i - (float)(H*W/3.0));
            best_w = i;
        }
    }
    ll rest = H*W - H * best_w;
    if (H%2==0 || (W-best_w)%2==0){
        min_cands.push_back(abs(H*best_w - rest/2));
    }else{
        ll cand_a = max( abs( H*best_w - H*((W-best_w)/2+1) ), abs( H*best_w - H*((W-best_w)/2) ) );
        ll cand_b = max( abs( H*best_w - (W-best_w)*(H/2+1) ), abs( H*best_w - (W-best_w)*(H/2) ) );
        min_cands.push_back( min(cand_a, cand_b) );
    }

    // 縦を割ってみる
    best=INF;
    ll best_h;
    llrep(i,H){
        if (abs(W*i - (float)(H*W/3.0)) < best){
            best = abs(W*i - (float)(H*W/3.0));
            best_h = i;
        }
    }
    rest = H*W - W * best_h;
    if (W%2==0 || (H-best_h)%2==0){
        min_cands.push_back( abs(W*best_h - rest/2) );
    }else{
        ll cand_a = max( abs( W*best_h - W*((H-best_h)/2+1) ), abs( W*best_h - W*((H-best_h)/2) ) );
        ll cand_b = max( abs( W*best_h - (H-best_h)*(W/2+1) ), abs( W*best_h - (H-best_h)*(W/2) ) );
        min_cands.push_back( min(cand_a, cand_b) );
    }

    sort(min_cands.begin(), min_cands.end());
    cout << min_cands[0] << endl;

    return 0;
}
