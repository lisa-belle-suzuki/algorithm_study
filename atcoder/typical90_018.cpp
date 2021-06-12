# include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

ll E[1002];
ll T,L,X,Y,Q;


double atan_degree(double num){
    return atan(num) * 180 / M_PI;
}

double hypotenuse(double side1, double side2){
    return sqrt(pow(side1, 2) + pow(side2, 2));
}

double depression_angle(ll e){
    e %= T;
    double y = - double(L / 2.0) * sin(double(2*M_PI*e/T));
    double z = L/2.0 * (1 - cos(2*M_PI*e/T));

    return atan_degree(z / hypotenuse(X, (Y-y)));
}

int main(){
    cin >> T;
    cin >> L >> X >> Y;
    cin >> Q;
    for(ll i=0; i<Q; i++){
        cin >> E[i];
    }

    cout << fixed << setprecision(9);
    for(ll i=0; i<Q; i++){
        cout << depression_angle(E[i]) << endl;
    }

    return 0;
}