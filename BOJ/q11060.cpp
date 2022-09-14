#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int arr[MAX] = {0};
int dp[MAX] = {0};
int N,jump,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(dp,dp+MAX,-1);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	ans = 0;
	dp[1] = 0;
	for(int i=1;i<=N;i++) {
		if(dp[i] == -1) continue;
		for(int j=arr[i];j>0;j--) {
			if(i+j <= N && (dp[i+j] == -1 || dp[i+j] > dp[i]+1)) {
				dp[i+j] = dp[i]+1;
			}
		}
	}
	ans = dp[N];
	cout<<ans<<"\n";
	return 0;	
}