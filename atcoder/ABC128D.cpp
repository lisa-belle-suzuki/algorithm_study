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

vector<ll> V,l_sum, r_sum, c;

int main(){
    ll N,K,v,sum,l_max,r_max,rest_trial;
    cin >> N >> K;

    sum=0;
    llrep(i,N){
        cin >> v;
        V.push_back(v);
        sum += v;
        l_sum.push_back(sum);
    }
    sum=0;
    llrep(i,N){
        sum += V[N-1-i];
        r_sum.push_back(sum);
    }

    cout << "aaa" << endl;

    ll sum_max = 0;
    for(ll left=0; left<=K; left++){//left:左の個数
        //左
        cout << "bbb" << endl;
        l_max = 0;
        for(ll rest_trial=0; rest_trial<left; rest_trial++){
            sum = l_sum[rest_trial];
            copy(V.begin(), V.begin()+left-1, c.begin());//c:copy先
            sort(c.begin(), c.end());
            ll add=0;
            llrep(k,rest_trial){
                if (c[k]<0) add += (-2 * c[k]);
            }
            chmax(l_max, sum + add);
            c.clear();
        }
        //右
        cout << "ccc" << endl;
        r_max = 0;
        ll right = K - left;
        for(ll rest_trial=0; rest_trial<right; rest_trial++){
            sum = r_sum[rest_trial];
            cout << "ddd" << endl;
            copy(V.begin()-rest_trial+1, V.end(), c.begin());//c:copy先
            sort(c.begin(), c.end());
            llrep(i,c.size()){
                cout << "c[i] = " <<  c[i] << endl;
            }
            cout << "eee" << endl;
            ll add=0;
            llrep(k,rest_trial){
                if (c[k]<0) add += (-2 * c[k]);
            }
            cout << "fff" << endl;
            chmax(r_max, sum + add);
            c.clear();
        }
        cout << "ggg" << endl;
        chmax(sum_max, l_max + r_max);
    }

    cout << sum_max << endl;

    return 0;
}
