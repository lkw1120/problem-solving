#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e5+1;
ll arr[MAX] = {0};
ll dp[MAX] = {0};
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		dp[i] = dp[i-1]+arr[i];
	}
	ans = 0;
	for(int i=2;i<N;i++) {
		ans = max(ans,dp[N]-arr[1]-arr[i]+dp[N]-dp[i]);
	}
	for(int i=2;i<N;i++) {
		ans = max(ans,dp[N]-arr[N]-arr[i]+dp[i-1]);
	}
	for(int i=2;i<N;i++) {
		ans = max(ans,dp[i]-arr[1]+dp[N]-dp[i-1]-arr[N]);	
	}
	cout<<ans<<"\n";
	return 0;
}