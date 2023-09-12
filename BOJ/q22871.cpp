#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 5001;
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
	}
	fill(dp,dp+MAX,LONG_MAX);
	dp[1] = 0;
	dp[2] = abs(arr[2]-arr[1])+1;
	for(int i=3;i<=N;i++) {
		for(int j=1;j<i;j++) {
			ll next = (i-j)*(1+abs(arr[j]-arr[i]));
			dp[i] = min(dp[i],max(dp[j],next));
		}
	}
	ans = dp[N];
	cout<<ans<<"\n";
	return 0;
}