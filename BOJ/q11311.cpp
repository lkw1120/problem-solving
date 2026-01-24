#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        ll a,b,d;
        cin>>a>>b>>d;
        ll g = gcd(a,b);
        if(d%g == 0) {
            cout<<"Yes"<<"\n";
        }
        else {
            cout<<"No"<<"\n";
        }
    }
    return 0;
}