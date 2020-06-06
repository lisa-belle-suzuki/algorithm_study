# include<bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long int ull;
unordered_map<int, int> pow_memo;
 
bool isFoundInMap(int N){
    auto itr = pow_memo.find(N);
    if( itr != pow_memo.end() ) return true;
    else return false;
}
 
int pow_int(int num, int N){
    // cout << "N = "<< N << endl;
    if (N==0){
        pow_memo[0] = 1;
        // cout << pow_memo[0] << endl;
        return 1;
    }
    if (N==1){
        pow_memo[1] = num;
        // cout << pow_memo[1] << endl;
        return num;
    }
    if (isFoundInMap(N)){
        // cout << pow_memo[1] << endl;
        return pow_memo[N];
    }
 
    int half = pow_int(num, N/2);
    if (half > (4 * 1e4)){
        // cout << "over ";
        pow_memo[N] = 1e9+1;
        // cout << pow_memo[N] << endl;
        return 1e9+1;
    }
 
    int return_num;
    if (N%2==0){
        return_num = half * half;
    }else{
        return_num = half * half * num;
    }
 
    if (return_num > 1e9){
        pow_memo[N] = 1e9+1;
        // cout << "over ";
        // cout << pow_memo[N] << endl;
        return 1e9 + 1;
    }else{
        pow_memo[N] = return_num;
        // cout << pow_memo[N] << endl;
        return return_num;
    }
}
 
int main(){
    int A, R, N;
    cin >> A >> R >> N;
    ull pow_num = pow_int(R, N-1);
    if (pow_num > 1e9){
        cout << "large" << endl;
    }else if (pow_num * A > 1e9){
        cout << "large" << endl;
    }else{
        cout << pow_num * A << endl;
    }
    return 0;
}