#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M;
double ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ll g = gcd(N,M);
    double tmp;
    if((N/g)%2 == 0) {
        tmp = N/4.0;
    }
    else {
        tmp = N/4.0-pow(g,2)/(4.0*N);
    }
    ans = tmp*10000.0/(N+M);
    cout<<fixed<<setprecision(4)<<ans<<"\n";
    return 0;
}