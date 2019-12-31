# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

bool is(vector<int> ant, int k){
    for (int i=0; i<4; i++){
        for (int j=i; j<5; j++){
            if (ant[i] - ant[j] < -k || ant[i] - ant[j] > k){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int a,k;
    vector<int> ant;
    for (int i=0; i<5; i++){
        cin >> a;
        ant.push_back(a);
    }
    cin >> k;

    if (is(ant,k)){
        cout << "Yay!" << endl;
    }else{
        cout << ":(" << endl;
    }


    return 0;
}
