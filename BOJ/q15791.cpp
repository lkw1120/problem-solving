#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e6+1;
const int MOD = 1e9+7;
ll facto[MAX] = {0};
ll M,N,K,ans;
void init() {
	facto[0] = 1;
	for(int i=1;i<MAX;i++) {
		facto[i] = (facto[i-1]*i)%MOD;
	}
}
ll modpow(ll a, ll n, ll p) {
	ll res = 1;
	while(n) {
		if(n & 1) {
			res = res*a%p;
		}
		a = a*a%p;
		n/=2;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>N>>M;
	ll A = facto[N];
	ll B = facto[M]*facto[N-M]%MOD;
	ans = A*modpow(B,MOD-2,MOD)%MOD;
	cout<<ans<<"\n";
	return 0;
}