#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <numeric>
#include <set>
using namespace std;
typedef long long unsigned int ll;

ll my_gcd(ll a, ll b) {
  if(a < b) my_gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(){
    ll n, min_of_gcd, input_num;
    cin >> n;
    vector<ll> a[n+3];
    cin >> a;
    // for (ll i=0; i<n; i++) {
        // cin >> a[i];

        // cin >> input_num;
        // a[i] = input_num;
    // }
    min_of_gcd = 1000000000;
    for (ll i=0; i<n-1; i++) {
        for (ll j=i+1; j<n; j++) {
            if ( my_gcd(a[i], a[j]) < min_of_gcd ) {
                min_of_gcd = my_gcd(a[i], a[j]);
            }
        }
    }
    cout << min_of_gcd << endl;
    return 0;
}
