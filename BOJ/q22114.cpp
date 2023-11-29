#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX];
int dp[MAX][2];
int N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=1;i<N;i++) {
		cin>>arr[i];	
	}
	dp[1][0] = dp[1][1] = 1;
	for(int i=2;i<=N;i++) {
		if(arr[i-1] <= K) {
			dp[i][0] = dp[i-1][0]+1;
			dp[i][1] = dp[i-1][1]+1;
		}
		else {
			dp[i][0] = 1;
			dp[i][1] = dp[i-1][0]+1;
		}
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		ans = max(max(dp[i][0],dp[i][1]),ans);
	}
	cout<<ans<<"\n";
	return 0;
}