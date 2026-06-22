#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
ll X,Y,ans;
ll factorial(ll n) {
	ll res = 1;
	for(int i=1;i<=n;i++) {
		res = res*i%MOD;
	}
	return res;
}
ll modpow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res*a%MOD;
        a = a*a%MOD;
        n>>=1;
    }
    return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>X>>Y;
	ans = 0;
	if((X+Y)%3 == 0) {
		ll a,b,x,y;
		a = (2*Y-X)/3;
		b = (2*X-Y)/3;
		if(0 <= a && 0 <= b) {
			x = factorial(a+b);
			y = factorial(a)*factorial(b)%MOD;
			ans = x*modpow(y,MOD-2)%MOD;
		}
	}
	cout<<ans<<"\n";
	return 0;
}