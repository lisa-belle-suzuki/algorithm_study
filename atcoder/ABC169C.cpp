# include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
ull A;
string B;

int main(){
    cin >> A >> B;
    string B_ = B.substr(0, B.size()-3) + B.substr(B.size()-2, 2);
    // cout << B_ << endl;
    ull ans = A * stoi(B_);
    // cout << ans << endl;
    cout << ans/100 << endl;
    return 0;
}