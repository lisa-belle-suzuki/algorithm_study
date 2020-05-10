#include <bits/stdc++.h>

using namespace std;

int pow(int x, int n){
    if (n==0) return 1;
    if (n==1) return x;
    int half = pow(x, n/2);
    if (n%2==0){
        return half * half;
    }else{//n%2==1
        return half * half * x;
    }
}

int main(){
    int X;
    cin >> X;
    for(int A=-118; A<=119; A++){
        for(int B=-119; B<=118; B++){
            if (pow(A,5) - pow(B,5)==X){
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }
    return 0;
}