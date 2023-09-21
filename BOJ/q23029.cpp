#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e5+1;
ll arr[MAX] = {0};
ll dp[MAX][3] = {0};
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	dp[1][1] = arr[1]/2;
	dp[1][2] = arr[1];
	ans = arr[1];
	for(int i=2;i<=N;i++) {
		dp[i][0] = max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
		dp[i][1] = dp[i-1][2]+arr[i]/2;
		dp[i][2] = dp[i-1][0]+arr[i];
		ans = max(max(max(dp[i][0],dp[i][1]),dp[i][2]),ans);
	}
	cout<<ans<<"\n";
	return 0;
}