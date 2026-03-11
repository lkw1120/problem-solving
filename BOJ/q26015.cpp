#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ld term = 1.0L;
    if(1 < N) {
        term = powl(-0.5L,(ld)(N-1));
    }
    ld p = 1.0L/3.0L+(2.0L/3.0L)*term;
    ld t = 1.0L-p;
    p*=100.0L;
    t*=100.0L;
    cout<<fixed<<setprecision(6);
    cout<<p<<" "<<t<<"\n";
    return 0;
}