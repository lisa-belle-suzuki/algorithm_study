# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>
#include <numeric>

typedef long long int ll;


using namespace std;

int main() {

    ll N,a;
    vector<ll> A;
    cin >> N;

    ll sum = 0, nega_cnt, abs_min = 1000000000;

    for(ll i=0; i<N; i++){
        cin >> a;
        A.push_back(a);
        if (a < 0) {
            nega_cnt ++;
        }
        sum += abs(a);
        if (abs(a) < abs_min){
            abs_min = abs(a);
        }
    }

    if (nega_cnt %2 ==0){
        cout << sum << endl;
    }else{
        // cout << "aaaa" << endl;
        // cout << sum << endl;
        // cout << abs_min << endl;
        cout << sum - 2 * abs_min << endl;;
    }

    return 0;
}
