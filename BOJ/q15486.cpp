#include<bits/stdc++.h>
#define MAX 1500002
using namespace std;
int arr[MAX][2] = {0};
int dp[MAX] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i][0]>>arr[i][1];
	}
	ans = 0;
	for(int i=N;i>0;i--) {
		if(i+arr[i][0]-1 > N) {
			dp[i] = dp[i+1];
		}
		else {
			dp[i] = max(dp[i+arr[i][0]]+arr[i][1],dp[i+1]);
		}
	}
	ans = dp[1];
	cout<<ans<<"\n";
	return 0;
}