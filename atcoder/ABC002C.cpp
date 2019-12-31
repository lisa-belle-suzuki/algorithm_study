# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    by -= ay;
    cy -= ay;

    bx -= ax;
    cx -= ax;

  printf("%.5f\n", (double)abs(bx * cy - by * cx) / 2.0);
}
