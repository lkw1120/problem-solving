#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,P,Q,ans;
map<ll,ll> dp;
ll solve(ll n) {
	if(dp.count(n)) {
		return dp[n];
	}
	else {
		return dp[n] = solve(n/P)+solve(n/Q);
	} 
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>P>>Q;
	dp[0] = 1;
	ans = solve(N);
	cout<<ans<<"\n";
	return 0;
}