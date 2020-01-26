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
#include <unordered_map>
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

class Solution {
public:

    string longestPalindrome(string s) {
        bool dp[1002][1002];
        string resLongestStr = "";

        if (s==""){
            return "";
        }

        // 1文字組
        for (int i=0; i<s.length(); i++){
            dp[i][i+1] = true;
            if (resLongestStr.length() < 1){
                resLongestStr = s[0];
            }
            for (int k=1; ( (i-k>=0) && (i+1+k <= s.length()) ); k++){
                if (dp[i-k+1][i+k]==true){
                    if (s[i-k] == s[i+k]){
                        dp[i-k][i+1+k] = true;
                        int curLength = (i+1+k) - (i-k);
                        if (curLength > resLongestStr.length()){
                            // cout << s.substr(i-k,curLength) << endl;
                            resLongestStr = s.substr(i-k, curLength);
                        }
                    }else{
                        dp[i-k][i+1+k] = false;
                    }
                }
            }
        }

        // 2文字組
        for (int i=0; i<s.length()-1; i++){
            if (s[i]==s[i+1]){
                // cout << "2文字組 " << i << ":" << i+1 << s.substr(i,2) << endl;
                dp[i][i+2] = true;
                if (resLongestStr.length() < 2){
                    resLongestStr = s.substr(i,2);
                }
            }else{
                dp[i][i+2] = false;
            }
            for (int k=1; ( (i-k>=0) && (i+2+k <= s.length()) ); k++){
                if (dp[i-k+1][i+1+k]==true){
                    // cout << "test:" << s.substr(i-k, (i+2+k-i+k)) << endl;
                    if (s[i-k] == s[i+1+k]){
                        dp[i-k][i+2+k] = true;
                        int curLength = (i+2+k) - (i-k);
                        if (curLength > resLongestStr.length()){
                            resLongestStr = s.substr(i-k, curLength);
                        }
                    }else{
                        dp[i-k][i+1+k] = false;
                    }
                }
            }
        }
        return resLongestStr;
    }
};


int main(){
    string testStr;
    cin >> testStr;
    Solution solution;
    cout << solution.longestPalindrome(testStr) << endl;

    return 0;
}
