#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll arr[51] = {0};
ll dp[51] = {0};
ll N,K,ans;
ll find(ll n, ll k) {
	if(k == 0) {
		return 0;
	}
	if(n == 0) {
		return 1;
	}
	ll mid = arr[n]/2+1;
	if(mid < k) {
		k-=mid;
		return dp[n-1]+1+find(n-1,k);
	}
	else if(k < mid) {
		k--;
		return find(n-1,k);
	}
	else {
		return dp[n-1]+1;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	arr[0] = dp[0] = 1;
	for(int i=1;i<=N;i++) {
		arr[i] = arr[i-1]*2+3;
		dp[i] = dp[i-1]*2+1;
	}
	ans = find(N,K);
	cout<<ans<<"\n";
	return 0;
}