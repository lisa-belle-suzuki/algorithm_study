# include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

int main(){
    ull N, sum=0, upper;
    cin >> N;
    for(ull i=1; i<=N; i++){
        upper = N/i;
        sum += (i * (1 + upper) * upper)/2;
    }
    cout << sum << endl;

    return 0;
}