#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define Rep(i, n) for(int i = 1; i <= (int)(n); i++)

const long long int INF = 1e14;
typedef long long int ll;

using namespace std;

bool canSell(int T,int N, int M, queue<int> A, queue<int> B){
    if (N<M) return false;
    else{
        int a,b;
        while(!B.empty()){
            b = B.front();
            B.pop();
            a = A.front();
            A.pop();
            while (! (a<=b && (b-a)<=T) ){
                a = A.front();
                A.pop();
                if (A.empty()) cout << "aaa" << endl; return false;
                if (a > b) return false;
            }
        }
    }
    return true;
}

int main(){
    int T,N,M,a,b;
    queue<int> A,B;

    cin >> T;
    cin >> N;
    rep(i,N) cin >> a; A.push(a);
    cin >> M;
    rep(i,M) cin >> b; B.push(b);

    if (canSell(T,N,M,A,B)) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}
