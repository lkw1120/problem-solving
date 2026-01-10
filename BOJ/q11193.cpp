#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
ll modpow(ll a, ll n, ll p) {
    if(n == 0) return 1;
    ll half = modpow(a,n/2,p);
    half = (half*half)% p;
    if(n%2 == 1) half = (half*a)%p;
    return half;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll fact = 1;
    ll cnt2 = 0;
    ll cnt5 = 0;
    for(int i=1;i<=N;i++) {
        int x = i;
        while(x%2 == 0) {
            x/=2;
            cnt2++;
        }
        while(x%5 == 0) {
            x/=5;
            cnt5++;
        }
        fact = (fact*x)%1000;
    }
    ll d = cnt2-cnt5;
    ll mod = modpow(2,d,1000);
    ans = (fact*mod)%1000;
    if(N <= 6) {
        cout<<ans<<"\n";
    }
    else {
        cout<<setw(3)<<setfill('0')<<ans<<"\n";
    }
    return 0;
}