#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,P,Q,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
bool check(ll x) {
    return x > 0 && (x&(x-1)) == 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        string str;
        cin>>str;
        int pos = str.find('/');
        P = stoll(str.substr(0,pos));
        Q = stoll(str.substr(pos+1));
        ll g = gcd(P,Q);
        P/=g;
        Q/=g;
        cout<<"Case #"<<tc<<": ";
        if(!check(Q)) {
            cout<<"impossible"<<"\n";
        }
        else {
            ans = 0;
            while(P < Q) {
                P*=2;
                ans++;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}