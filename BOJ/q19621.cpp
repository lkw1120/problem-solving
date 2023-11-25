#include<bits/stdc++.h>
using namespace std;
int arr[26];
int dp[26];
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		int a,b;
		cin>>a>>b>>arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[2];
	for(int i=3;i<=N;i++) {
		for(int j=i-2;j>0;j--) {
			dp[i] = max(dp[j]+arr[i],dp[i]);
		}
	}
	ans = *max_element(dp+1,dp+N+1);
	cout<<ans<<"\n";
	return 0;
}