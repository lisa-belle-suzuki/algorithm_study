# include <iostream>
# include <vector>

using namespace std;

int main(){
    int N,Y;
    cin >> N >> Y;
    Y /= 1000;
    for (int i=0; i<=(Y/10); i++) {
        int j_max = (Y-10*i)/5;
        for (int j=0; j<=j_max; j++) {
            if (N - i - j >= 0) {
                if (10 * i + 5 * j + 1 * (N-i-j) == Y) {
                    cout << i << " " << j << " " << (N-i-j) << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}