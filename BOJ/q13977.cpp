#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 4e6+1;
const int MOD = 1e9+7;
ll facto[MAX] = {0};
ll M,N,K,ans;
void init() {
	facto[0] = 1;
	for(int i=1;i<MAX;i++) {
		facto[i] = (facto[i-1]*i)%MOD;
	}
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
	init();
	cin>>M;
	while(M--) {
		cin>>N>>K;
		ll A = facto[N];
		ll B = facto[K]*facto[N-K]%MOD;
		ans = A*modpow(B,MOD-2)%MOD;
		cout<<ans<<"\n";
	}
	return 0;
}