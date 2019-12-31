#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

int main(){
    ll a, b;
    cin >> a >> b;
    if (b % a == 0){
        cout << a+b << endl;
    }else{
        cout << -a+b << endl;
    }
    return 0;
}