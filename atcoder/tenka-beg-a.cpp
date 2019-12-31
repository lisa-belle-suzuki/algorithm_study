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
  string k;
  cin >> k;
  if(k.length()==2){
    cout << k << endl;
  }else{
    for(int i=0; i<3; i++) {
        cout << k[2-i];
    }
        cout << endl;
  }
  return 0;
}
