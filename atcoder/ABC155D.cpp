#include <bits/stdc++.h>

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

ll gcd(ll a, ll b){
    ll temp;
	while (a % b != 0){
		temp = b;
		b = a % b;
		a = temp;
	}
	return b;
}

ll lcm(ll a, ll b){
  return a * b / gcd(a,b);
}

char alphabet[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
};

ll digit__(ll num){
    ll cnt=1;
    while(num > 10){
        cnt ++;
        num /= 10;
    }
    return cnt;
}



tuple<int, int> countXorLess(vector<int> sortedA, int X, int maxVal, int maxNegaIdx, int minPosiIdx){
    // left(0~maxNega)
        // right(最後~minPosiIdx)
            // Xより大きくなったら終わり

    int cnt=0;
    int rightIdx = minPosiIdx; 
    for (int i=0; i<=maxNegaIdx; i++){
        int leftVal = sortedA[i];
        int j = rightIdx;
        while (j<sortedA.size()){
            // rightが条件を満たすまで
            int product = leftVal * sortedA[j];
            if (product <= X){
                cnt += (sortedA.size()-j);
                rightIdx = j;
                if (product > maxVal) maxVal = product;
                break;
            }
            j++;
        }
    }

    return forward_as_tuple(cnt, maxVal);
}


int KthNum(vector<int> sortedA, int K){
    auto zeroOrMorePtr = lower_bound(sortedA.begin(), sortedA.end(), 0);
    int maxNegaIdx = zeroOrMorePtr - sortedA.begin() - 1;
    auto overZeroPtr = upper_bound(sortedA.begin(), sortedA.end(), 0);
    int minPosiIdx = overZeroPtr - sortedA.begin();

    int minNega = sortedA.front();
    int maxNega = sortedA[maxNegaIdx];
    int minPosi = sortedA[minPosiIdx];
    int maxPosi = sortedA.back();
    int minProduct = minNega * maxPosi;//最小値
    int maxProduct = maxNega * minPosi;//最大値

    // X以下の個数は何個？
    int left = minProduct; 
    int right = maxProduct;
    cout << "left: "<< left << " right: " << right << endl;
    while(1){
        int X = (left + right) / 2;
        cout << "X = " << X << endl;
        auto [cntXorLess, maxXorLess]  = countXorLess(sortedA, X, minProduct, maxNegaIdx, minPosiIdx);
        if (cntXorLess == K){
            cout << "cntXorLess == K " << cntXorLess << "個" << endl;
            return maxXorLess;
        }else if (cntXorLess < K){
            cout << "cntXorLess < K " << cntXorLess << "個" << endl;
            if (left == X) return maxXorLess;
            left = X;
        }else{
            cout << "cntXorLess > K " << cntXorLess << "個" << endl;
            if (right == X) return maxXorLess;
            right = X;
        }

    }
    cout << "No value found...." << endl;
    return 0;
}


int main(){
    int N,K,a,zeroCnt=0, negaCnt=0, posiCnt=0;
    vector<int> A;

    cin >> N >> K;
    rep(i,N){
        cin >> a;
        if (a==0) zeroCnt++;
        else if (a>0) posiCnt++;
        else negaCnt++;
        A.push_back(a);
    }

    sort(A.begin(), A.end());

    if (K < negaCnt * posiCnt){
        cout << "負" << endl;
        cout << KthNum(A, K) << endl;
    }else if (K < (negaCnt * posiCnt + zeroCnt * (N - zeroCnt)) ){
        cout << 0 << endl;
    }else{
        cout << "正" << endl;
    }

    return 0;
}
