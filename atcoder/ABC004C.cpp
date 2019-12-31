# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

typedef long long ll;

using namespace std;

int main() {
    ll N,j;
    cin >> N;
    j = (N-1)%30;
    string original_str="0123456";
    for(ll i=0; i<=j; i++){
        ll pos = i%5 + 1;
        char tmp = original_str[pos];
        original_str[pos] = original_str[pos+1];
        original_str[pos+1] = tmp;
    }
    for (ll i=1; i<=6; i++){
        cout << original_str[i];
    }
    cout << "" << endl;
    return 0;
}
