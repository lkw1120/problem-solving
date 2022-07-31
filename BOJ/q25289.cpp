#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int arr[MAX] = {0};
int dp[101] = {0};
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
	for(int d=-99;d<=99;d++) {
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;i++) {
			if (arr[i] - d < 1 || arr[i] - d > 100) {
				dp[arr[i]] = 1;
			}
			else {
				dp[arr[i]] = dp[arr[i] - d] + 1;
			}
			ans = max(ans, dp[arr[i]]);
		}
	}
	cout<<ans<<"\n";
	return 0;	
}