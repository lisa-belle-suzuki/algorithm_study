# include <iostream>

using namespace std;

int howManyDivision(int num) {
    int count = 0;
    while(num % 2 == 0) {
        count += 1;
        num /= 2;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int a[n+2];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int min = howManyDivision(a[0]);
    for (int i=1; i<n; i++){
        if (howManyDivision(a[i]) < min) {
            min = howManyDivision(a[i]);
        }
    }
    cout << min << endl;

    return 0;
}