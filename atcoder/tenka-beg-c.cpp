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
#include <deque>

#define ll long long

using namespace std;

ll calc_diff(deque<ll> deq){
    ll diff=0;
    for(ll i=0; i<deq.size()-1; i++){
        diff += abs(deq[i]-deq[i+1]);
        //cout << "diff= "<<diff<<endl;
    }
    return diff;
}

int main(int argc, char* argv[]){
    ll n,k,min=0,max=0;
    deque<ll> a,ret;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> k;
        a.push_back(k);
    }
    sort(a.begin(), a.end());
    ll i=0;
    while(1){
        if (a.size()==0){
            break;
        }
        min=a.front();
        a.pop_front();
        if (a.size()==0){
            //cout << "i= "<< i <<"min: "<<min<< endl;            
            if (abs(ret[0]-min)>abs(ret.back()-min)){
                ret.push_front(min);
            }else{
                ret.push_back(min);
            }
            break;
        }
        max=a.back();
        a.pop_back();
        if(i%2==0){
            ret.push_front(min);
            ret.push_back(max);
        }else{
            ret.push_front(max);
            ret.push_back(min);
        }
        i++;
        //cout << "i= "<< i <<"min: "<<min<<" max "<<max<< endl;
    }
    ///calc diff
    ll answer = calc_diff(ret);
    cout << answer << endl;
    return 0;
}
