#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
int arr[MAX] = {0};
int dp[MAX][2] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	dp[1][0] = dp[1][1] = 1;
	ans = 1;
	for(int i=2;i<=N;i++) {
		if(arr[i-1] < arr[i]) {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = dp[i-1][0]+1;
		}
		else if(arr[i] < arr[i-1]) {
			dp[i][0] = dp[i-1][1]+1;
			dp[i][1] = dp[i-1][1];
		}
		else {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = dp[i-1][1];
		}
		ans = max(max(dp[i][0],dp[i][1]),ans);
	}
	cout<<ans<<"\n";
	return 0;
}