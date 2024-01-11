#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int arr[MAX][2];
int dp[MAX][2];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i][0]>>arr[i][1];
	}
	dp[1][0] = arr[1][0];
	dp[1][1] = arr[1][1];
	for(int i=2;i<=N;i++) {
		dp[i][0] = arr[i][0] + max(dp[i-1][0]+abs(arr[i][1]-arr[i-1][1]),dp[i-1][1]+abs(arr[i][1]-arr[i-1][0]));
		dp[i][1] = arr[i][1] + max(dp[i-1][0]+abs(arr[i][0]-arr[i-1][1]),dp[i-1][1]+abs(arr[i][0]-arr[i-1][0]));
	}
	ans = max(dp[N][0],dp[N][1]);
	cout<<ans<<"\n";
	return 0;
}