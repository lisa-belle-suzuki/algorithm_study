# include <iostream>

using namespace std;

int sum_of_digits(int num) {
    int rest, sum=0;
    while(num != 0) {
        rest = num % 10;
        sum += rest;
        num /= 10;
    }
    return sum;
}

int main(){
    int n,a,b;
    cin >> n >> a >> b;

    int res = 0;
    for (int i=1; i<=n; i++) {
        if (sum_of_digits(i) >= a && sum_of_digits(i) <= b) {
            res += i;
        }
    }
    cout << res << endl;

}