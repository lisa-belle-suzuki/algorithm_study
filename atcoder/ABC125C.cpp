# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>
#include <numeric>

// typedef long long int;

using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(a-(a/b)*b,b);
    return gcd(a,b-(b/a)*a);
}

int main() {
    int N,a;
    vector<int> A;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> a;
        A.push_back(a);
    }
    vector<int> gcd_from_left, gcd_from_right;

    int cur_from_left = A[0];
    gcd_from_left.push_back(cur_from_left);
    int cur_from_right = A[N-1];
    gcd_from_right.push_back(cur_from_right);

    // 左から
    bool coprime_from_left = false; // 互いに素
    for (int i=1; i<N; i++){
        if (coprime_from_left==true){
            gcd_from_left.push_back(1);
        }else{
            cur_from_left = gcd(cur_from_left, A[i]);
            if (cur_from_left == 1){
                coprime_from_left = true;
                gcd_from_left.push_back(1);
            }else{
                gcd_from_left.push_back(cur_from_left);
            }
        }
    }

    // 右から
    bool coprime_from_right = false; // 互いに素
    for (int i=1; i<N; i++){//i:右から何個めかをあらわす(0,1,2,...)
        if (coprime_from_right){
            gcd_from_right.push_back(1);
        }else{
            cur_from_right = gcd(cur_from_right, A[N-i-1]);
            if (cur_from_right == 1){
                coprime_from_right = true;
            }
            gcd_from_right.push_back(cur_from_right);
        }
    }

    int max=gcd_from_right[N-2];


    for (int i=1; i<N; i++){
        int max_candidate = gcd( gcd_from_left[i-1], gcd_from_right[N-2-i] );
        if (max_candidate > max){
            max = max_candidate;
        }
    }

    cout << max << endl;

    return 0;
}
