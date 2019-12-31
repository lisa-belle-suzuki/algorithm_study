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

int sum(int number){
  int num=number,sum=0;
  while(number){
    sum += number%10;
    number/=10;
  }
  return sum;
}

int main(int argc, char* argv[]){
  int k;
  cin >> k;
  if(k<10){
    for (int i = 1; i <= k; ++i)
    {
      cout << i << endl;
    }
  }else{
    for (int i = 1; i < 10; ++i)
    {
      cout << i << endl;
    }
    //
  }

  return 0;
}
