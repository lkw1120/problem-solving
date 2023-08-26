#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX] = {0};
int dp[MAX*10] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	for(int i=1;i<=N;i++) {
        dp[arr[i]] = max(dp[arr[i]],dp[arr[i]-1]+1);
        ans = max(ans,dp[arr[i]]);
	}
	cout<<ans<<"\n";
	return 0;
}