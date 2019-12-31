# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

typedef long long ll;

using namespace std;

int main() {
    int N,v,c;
    vector<int> V,C;
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> v;
        V.push_back(v);
    }
    for (int i=0;i<N;i++){
        cin >> c;
        C.push_back(c);
    }
    int sum=0;
    for (int i=0;i<N;i++){
        if (V[i] - C[i] > 0){
            sum += (V[i] - C[i]);
        }
    }
    cout << sum << endl;

    return 0;
}
