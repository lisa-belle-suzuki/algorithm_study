#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int A,B,N,x;
    cin >> A >> B >> N;
    x = min(N, B-1);
    cout << (A*x/B)-A*(x/B) << endl;
    return 0;
}