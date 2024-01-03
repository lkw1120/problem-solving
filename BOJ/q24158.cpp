#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1001];
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	fill(dp+1,dp+N+1,1);
	ans = 1;
	for(int i=2;i<=N;i++) {
		for(int j=i-1;j>0;j--) {
			if(arr[j] < arr[i]) {
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		ans = max(ans,dp[i]);
	}
	cout<<ans<<"\n";
	return 0;
}