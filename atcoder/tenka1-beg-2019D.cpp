# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

bool canMakeTriangle(long long a, long long b, long long c){
    if (a + b > c && b + c > a && c + a >> b){
        return true;
    }else{
        return false;
    }
}

int main() {



    return 0;
}
