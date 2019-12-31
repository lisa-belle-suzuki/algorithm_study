#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <typeinfo>
#include <stdlib.h>

#define ll long long

using namespace std;


vector<ll> operation(vector<ll> x){
    ll a=x[0];
    ll b=x[1];
    if (a%2 == 1){
        a -=1;
    }
    ll give = a/2;
    a -= give;
    b += give;
    vector<ll> re;
    re.push_back(a);
    re.push_back(b);
    return re;
}

vector<ll> operation2(vector<ll> x){
    ll a=x[0];
    ll b=x[1];
    if (b%2 == 1){
        b -=1;
    }
    ll give = b/2;
    b -= give;
    a += give;
    vector<ll> re;
    re.push_back(a);
    re.push_back(b);
    return re;
}


int main(int argc, char* argv[]){
  ll a,b,k;
  cin >> a>>b>>k;
  vector<ll> result;
  result.push_back(a);
  result.push_back(b);
  for(ll i=0;i<k;i++){
      if (i%2==0){
          result=operation(result);
      }else{
          result=operation2(result);
      }
  }
  cout << result[0]<<" " << result[1] << endl;
  return 0;
}
