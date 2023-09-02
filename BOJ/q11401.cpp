#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
ll N,K,ans;
ll factorial(ll n) {
	ll res = 1;
	for(int i=1;i<=n;i++) {
		res*=i;
		res%=MOD;
	}
	return res;
}
ll modpow(ll a, ll b) {
	if(b == 0) {
		return 1;
	}
	if(b%2 != 0) {
		return (modpow(a,b-1)*a)%MOD;
	}
	else {
		ll half = modpow(a,b/2)%MOD;
		return half*half%MOD;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	ll A = factorial(N);
	ll B = factorial(K)*factorial(N-K)%MOD;
	ans = A*modpow(B,MOD-2)%MOD;
	cout<<ans<<"\n";
	return 0;
}