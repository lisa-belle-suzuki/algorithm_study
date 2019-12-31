# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    int n,h, max=0, cnt=0;
    cin >> n;
    vector<int> height, maxs;
    for (int i=0; i<n; i++){
        cin >> h;
        if (h > max) {
            max = h;
        }
        if (h >= max) {
            cnt ++;
        }
    }
    cout << cnt << endl;

    return 0;
}
