#include <bits/stdc++.h>

using namespace std;

int fib[100];



int fibonacci(int n){
    if (n==0 || fib[n]!=0) return fib[n];
    if (n==1){
        fib[1] = 1;
        return fib[1];
    }else{
        fib[n] = fibonacci(n-1) + n;
        return fib[n];
    }
}

int main(){
    cout << fibonacci(2) << endl;
    cout << fibonacci(10) << endl;;
    return 0;
}