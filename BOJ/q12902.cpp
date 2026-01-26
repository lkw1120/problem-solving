#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    ll g = 0;
    ll mx = 0;
    for(int i=0;i<N;i++) {
        g = gcd(g,v[i]);
        mx = max(mx,v[i]);
    }
    ll tmp = mx/g-N;
    if(tmp%2) {
        cout<<"Alice"<<"\n";
    }
    else {
        cout<<"Bob"<<"\n";
    }
    return 0;
}