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

priority_queue<ll, vector<ll>, greater<ll> > queueA;

//平均にもっとも近い値
ll center_val(vector<ll> A){
    ll low = A[0];
    ll up = A[A.size()-1];
    double mean = (double)(low+up)/2;
    auto left = lower_bound(A.begin(), A.end(), mean);//イテレータなのでそのままllに変換とかはできない
    auto right = upper_bound(A.begin(), A.end(), mean);
    // ll min_diff = 2 * 1e9;
    // ll min_idx=-1;
    // for(ll i=0; i<A.size(); i++){
    //     double diff = (A[i] - mean);
    //     if (diff < min_diff){
    //         min_diff = diff;
    //         min_idx = i;
    //     }
    //     if (A[i] > mean) break; 
    // }
    ll idx_left = distance(A.begin(), left);
    ll idx_right = distance(A.begin(), right);
    if (A[idx_left] - mean < 1e-9){
        return idx_left;
    }
    if ( abs(A[idx_left]-mean) < abs(A[idx_right]-mean) ){
        return idx_left;
    }else{
        return idx_right;
    }
}

ll sum_diff(vector<ll> A, ll center_idx){
    ll sum = 0;
    ll center_val = A[center_idx];
    llrep(i,A.size()){
        sum += (A[i] - center_val);
    }
    return sum;
}

int main(){
    ll Q,a,b,b_sum=0;
    int num;
    cin >> Q;
    llrep(i,Q)
        cin >> num;
        if (num==1){
            //置き換え
            cin >> a >> b;
            queueA.push(a);
            b_sum += b;
        }else{
            //min_x
            ll min_x = center_val(queueA);
            cout << min_x << endl;
            //min(f(x))
            cout << sum_diff(queueA, min_x) + b_sum;
        }

    return 0;
}
