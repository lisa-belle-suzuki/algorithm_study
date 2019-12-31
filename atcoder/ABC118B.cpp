#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <set>
using namespace std;
typedef long long unsigned int ll;

int main(){
    ll n, m, k;
    ll idx_of_love;
    cin >> n >> m; cin.ignore();
    // cout << n << m << endl;
    vector<ll> loved_count(0, m+10);
    for (ll i=0;i<n;i++){
        cin >> k;
        // cout << "k=" << k << endl;
        for (ll j=0; j<k; j++){
            cin >> idx_of_love;
            // cout << idx_of_love;
            // cout << "oooo";
            loved_count[idx_of_love]++;
        }
    }
    cout << "aaa" << endl;

    ll loved_by_all_count = 0;
    for (ll i=1; i<m+1; i++){
        if (loved_count[i] == n){
            loved_by_all_count += 1;
            cout << "bbb" << endl;
        }
    }
    cout << loved_by_all_count << endl;

    // int l, i=0, a[10];
    // cin >> l;
    // while(1) {
    //     if (!std::cin.good()) break;
    //     // while(cin >> l && l != '\n'){
    //     a[i] = l;
    //     cout << a[i];
    //     i++;
    // }

    // int n;
    // while(cin >> n){
    //     cout << n << endl;
    // }
    return 0;
}