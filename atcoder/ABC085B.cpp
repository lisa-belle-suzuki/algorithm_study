# include <iostream>
# include <vector>

using namespace std;

int main(){
    int n, d;
    vector<bool> diameter(102);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> d;
        if (! diameter[d] ) {
            diameter[d] = 1;
        }
    }
    
    int how_many_different_d = 0;
    for (int i=0; i<102; i++) {
        how_many_different_d += diameter[i];
    }
    cout << how_many_different_d << endl;
}