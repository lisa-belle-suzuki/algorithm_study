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

const long long int INF = 1e9;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define Rep(i, n) for(int i = 1; i <= (int)(n); i++)
#define llrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define llRep(i, n) for(ll i = 1; i <= (ll)(n); i++)

using namespace std;

bool vector_finder(std::vector<int> vec, int number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
    }
  else { // 発見できなかったとき
    return false;
    }
}

vector<int> visited;
vector<int> visited_sum;
vector<int> edge[102];
bool NGflag=false;

void dfs(int now, int prev){
    for (int i : edge[now]){
        if (i != prev){
            if (vector_finder(visited, i)){
                NGflag = true;
                return;
            }else{
                visited.push_back(i);
                visited_sum.push_back(i);
                dfs(i, now);
            }
        }
    }
    return;
}

int main(){
    int N,M,v0,v1;
    cin >> N >> M;

    rep(i,M){
        cin >> v0 >> v1;
        edge[v0].push_back(v1);
        edge[v1].push_back(v0);
    }

    int cnt=0;
    Rep(i,N){
        if (!vector_finder(visited_sum, i)){
            NGflag = false;
            visited.clear();
            dfs(i, INF);
            if (!NGflag){
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
