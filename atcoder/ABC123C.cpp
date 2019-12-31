# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    long long n, a;
    cin >> n;
    vector<long long> batch;
    for(int i=0; i<5; i++){
        cin >> a;
        batch.push_back(a);
    }
    long long min_batch = *min_element(batch.begin(), batch.end());
    long long num_of_groups;
    if (n%min_batch==0){
        num_of_groups = n/min_batch;
    }else{
        num_of_groups = n/min_batch + 1;
    }


    cout << 5 + (num_of_groups - 1) << endl;

    return 0;
}
