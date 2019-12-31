# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    cout << max(2*x-1, max(2*y-1, x+y)) << endl;

    return 0;
}
