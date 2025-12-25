#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll P,K,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
ll find(ll p, ll q) {
    if(p == 1 && q == 1) {
        return 1;
    }
    if(p < q) {
        return find(p,q-p)*2;
    }
    else {
        return find(p-q,q)*2+1;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>P;
    while(P--) {
        cin>>K>>str;
        auto pos = str.find('/');
        ll p = stoll(str.substr(0,pos));
        ll q = stoll(str.substr(pos+1));
        ll g = gcd(p,q);
        p/=g,q/=g;
        ans = find(p,q);
        cout<<K<<" "<<ans<< "\n";
    }
    return 0;
}