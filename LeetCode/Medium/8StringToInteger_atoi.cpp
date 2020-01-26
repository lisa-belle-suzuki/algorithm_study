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

    int myAtoi(string str) {
        int startIdxOfFirstBlock = -1;
        int endIdxOfFirstBlock = -1;
        for (int i=0; i<str.length(); i++){
            if (startIdxOfFirstBlock == -1){
                // cout << "startIdxOfFirstBlock未発見" << endl;
                if ( str[i]!=' ' ){
                    startIdxOfFirstBlock = i;
                }
            }else{
                // cout << "startIdxOfFirstBlock発見済み" << endl;
                if ( str[i]==' ' ){
                    endIdxOfFirstBlock = i;
                    break;
                }
            }
            // cout << "str[i] = " << str[i] << endl;
        }
        if (startIdxOfFirstBlock == -1){
            // cout << "startIdxOfFirstBlock == -1 || endIdxOfFirstBlock==-1" << endl;
            return 0;
        }
        // cout << "endIdxOfFirstBlock = " << endIdxOfFirstBlock << endl;
        string intBlockStr = str.substr(startIdxOfFirstBlock, (endIdxOfFirstBlock - startIdxOfFirstBlock));
        // cout << "intBlockStr = " << intBlockStr << endl;
        if (isAllIntChar(intBlockStr)){
            long long result = intStrToInt(intBlockStr);
            int intMaxM = (Mypower(2,31)-1);
            int intMinM = (Mypower(2,31)) * (-1);
            if (result > intMaxM) return intMaxM;
            else if (result < intMinM) return intMinM;
            else return result;
        }else if (isFloatStrThenIntStr(intBlockStr)!=""){
            long long result = intStrToInt(isFloatStrThenIntStr(intBlockStr));
            int intMaxM = (Mypower(2,31)-1);
            int intMinM = (Mypower(2,31)) * (-1);
            if (result > intMaxM) return intMaxM;
            else if (result < intMinM) return intMinM;
            else return result;
        }else{
            return 0;
        }
    }

    string isFloatStrThenIntStr(string str){
        for (int i=0; i<str.length(); i++){
            if (isIntChar(str[i])){
                continue;
            }else if (str[i]=='.' && i>0){
                return str.substr(0, i);
            }else{
                return "";
            }
        }
        return str;
    }

    bool isIntChar(char c){
        if (c=='0'
        || c=='1'
        || c=='2'
        || c=='3'
        || c=='4'
        || c=='5'
        || c=='6'
        || c=='7'
        || c=='8'
        || c=='9'
        || c=='-'
        || c=='+'
        ){
            return true;
        }else{
            return false;
        }
    }

    bool isAllIntChar(string str){
        for (int i=0; i<str.length(); i++){
            if (isIntChar(str[i])){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }

    int intFromCharMy(char c){
        if (c=='0') return 0;
        else if (c=='1') return 1;
        else if (c=='2') return 2;
        else if (c=='3') return 3;
        else if (c=='4') return 4;
        else if (c=='5') return 5;
        else if (c=='6') return 6;
        else if (c=='7') return 7;
        else if (c=='8') return 8;
        else if (c=='9') return 9;
        return 0;
    }

    long long intStrToInt(string intStr){
        long long result = 0;
        for (int i=intStr.length()-1; i>=0; i--){
            if (i==0){
                if (intStr[i]=='-'){
                    return -result;
                }else if (intStr[i]=='+'){
                    return result;
                }else{
                    result += ( intFromCharMy(intStr[i]) * Mypower(10, intStr.length() - 1 - i));
                    return result;
                }
            }else{
                // cout << "i = " << i << endl;
                if (intStr[i]=='-' || intStr[i]=='+'){
                    return 0;
                }
                // cout << "Mypower(10, i) " << Mypower(10, i) << endl;
                result += ( intFromCharMy(intStr[i]) * Mypower(10, intStr.length() - 1 - i));
                // cout << "result = " << result << endl;
            }
        }
        // cout << "error" << endl;
        return 0;
    }



    long long Mypower(int n, int time){
        long long result = 1;
        for (int i=0; i<time; i++){
            result *= n;
        }
        return result;
    }

};


int main(){
    string testStr = "4193 with words";
    cin >> testStr;
    Solution solution;
    cout << solution.myAtoi(testStr) << endl;

    return 0;
}
