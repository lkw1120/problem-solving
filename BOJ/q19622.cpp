#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int arr[MAX];
int dp[MAX][2];
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
	for(int i=1;i<=N;i++) {
		dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
		dp[i][1] = max(dp[i-1][0],dp[i-2][1])+arr[i];
	}
	ans = max(dp[N][0],dp[N][1]);
	cout<<ans<<"\n";
	return 0;
}