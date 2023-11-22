#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[30];
int dp[12000][2];
int N,ans;
void fibo() {
	arr[1] = 1;
	for(int i=2;i<30;i++) {
		arr[i] = arr[i-1]+arr[i-2];	
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fibo();
	cin>>N;
	for(int i=1;i<=N;i++) {
		dp[i][0] = INF;
	}
	dp[2][0] = dp[2][1] = 1;
	for(int j=3;j<30;j++) {
		for(int i=arr[j];i<=N;i++) {
			dp[i][0] = min(dp[i][0],dp[i-arr[j]][0]+arr[j-1]);
			dp[i][1] = max(dp[i][1],dp[i-arr[j]][1]+arr[j-1]);
		}
	}
	cout<<dp[N][0]<<" "<<dp[N][1]<<"\n";
	return 0;
}