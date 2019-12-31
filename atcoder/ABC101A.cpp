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

int main(int argc, char* argv[]){
  int n,k,a,min=100000,min_idx=1000001;
  cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> a;
    a[i]=a;
    if (min > a){
      min=a;
      min_idx=i;
    }
  }
  

  // if (n == k){
  //   cout << 1 << endl;
  // }else if(n%(k-1) ==0){
  //   cout << n/(k-1) << endl;
  // }else{
  //   cout << n/(k-1)+1 << endl;
  // }

  return 0;
}
