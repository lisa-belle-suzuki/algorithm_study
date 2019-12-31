# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+2);

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    int i = 0;
    int alice=0, bob=0;
    while(a[i]) {
        if (i % 2 == 0) {
            alice += a[i];
        }else{
            bob += a[i];
        }
        i ++;
    }

    cout << alice - bob << endl;
}