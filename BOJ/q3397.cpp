#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int d;
    cin>>d;
    while(d--) {
        cin>>N;
        vector<ll> v(N+1);
        for(int i=1;i<=N;i++) {
            cin>>v[i];
        }
        ll g = gcd(v[1],v[2]);
        ll rest = v[2]/g;
        for (int i=3;i<=N && 1<rest;i++) {
            ll tmp = gcd(rest,v[i]);
            rest/=tmp;
        }
        if(rest == 1) {
            cout<<"YES"<<"\n";
        }
        else {
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}