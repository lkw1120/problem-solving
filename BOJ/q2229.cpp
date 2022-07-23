#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int dp[MAX][3] = {0};
int arr[MAX] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	ans = 0;
	dp[1][0] = dp[1][1] = arr[1];
	for(int i=2;i<=N;i++) {
		dp[i][0] = dp[i][1] = arr[i];
		for(int j=i;j>0;j--) {
			dp[i][0] = max(dp[i][0],arr[j]);
			dp[i][1] = min(dp[i][1],arr[j]);
			dp[i][2] = max(dp[i][2],abs(dp[i][0]-dp[i][1])+dp[j-1][2]);
		}
	}
	ans = dp[N][2];
	cout<<ans<<"\n";
	return 0;
}