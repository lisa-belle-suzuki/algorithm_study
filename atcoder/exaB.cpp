# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    int n;
    string colors;
    cin >> n;
    cin >> colors;

    int countR=0, countB=0;
    for (int i=0; i<n; i++){
        if (colors[i] == 'R'){
            countR ++;
        }else{
            countB ++;
        }
    }
    if (countR > countB) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl; 
    }
    return 0;
}
