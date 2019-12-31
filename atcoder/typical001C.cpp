#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <complex>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define Rep(i, n) for(int i = 1; i <= (int)(n); i++)

typedef long long ll;

using namespace std;

vector<complex<double> > dft(vector<complex<double> > f, int inv=0){
    int n = f.size();
    if (n == 1) return f;
    vector<complex<double> > f0(n/2),f1(n/2),ans(n);
    rep(i, n/2){
        f0[i] = f[i*2];
        f1[i] = f[i*2+1];
    }
    f0 = dft(f0,inv);
    f1 = dft(f1,inv);
    complex<double> p_zeta = complex<double>(1,0);
    rep(i,n){
        complex<double> zeta = polar(1.0, 2 * M_PI / n * (1 - inv * 2));
        ans[i] = f0[i%(n/2)] + f1[i%(n/2)] * p_zeta;
        p_zeta *= zeta;
    }
    return ans;
}
vector<complex<double> > convolution(vector<complex<double> >f, vector<complex<double> >g){
    int fs = f.size(), gs = g.size();
    int n = 1;
    while(n < fs + gs) n *= 2;
    f.resize(n,(complex<double>)0);
    g.resize(n,(complex<double>)0);
    vector<complex<double> > ff = dft(f);
    vector<complex<double> > gg = dft(g);

    vector<complex<double> > h(n);
    rep(i,n){
        h[i] = ff[i] * gg[i] / (complex<double>)n;
    }
    return dft(h,1);
}


int main(){
    int n;
    cin>>n;
    vector<complex<double> >a(n+1),b(n+1);
    rep(i,n)cin>>a[i+1]>>b[i+1];
    vector<complex<double> > ans=convolution(a,b);

    Rep(i, 2*n) cout<<(int)(ans[i].real()+0.1)<<endl;

    return 0;
}