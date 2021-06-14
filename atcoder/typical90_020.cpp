# include<bits/stdc++.h>

typedef unsigned long long int ll;

using namespace std;

ll power(ll num, ll expo){
    if (expo==0) return 1;
    ll half = power(num, expo/2);
    if (expo%2==0){
        return half * half;
    }else{
        return num * half * half;
    }
}

int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    if (a < power(c,b)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}