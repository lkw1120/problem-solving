#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
const int MAX = 1e6+1;
ll fac[MAX] = {0};
ll facinv[MAX] = {0};
ll inv[MAX] = {0};
ll N,R,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>R;
	fac[0] = facinv[0] = inv[1] = 1;
	for(int i=1;i<=N;i++) {
		fac[i] = fac[i-1]*i%MOD;
		facinv[i] = facinv[i-1]*inv[i]%MOD;
		inv[i+1] = (MOD-MOD/(i+1))*inv[MOD%(i+1)]%MOD;
	}
	ans = (fac[N]*facinv[R]%MOD)*facinv[N-R]%MOD;
	cout<<ans<<"\n";
	return 0;
}