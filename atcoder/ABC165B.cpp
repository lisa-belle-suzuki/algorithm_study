#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int X, money=100, cnt=0;
    cin >> X;
    while(money < X){
        money += money/100;
        cnt ++;
    }
    cout << cnt << endl;
    return 0;
}