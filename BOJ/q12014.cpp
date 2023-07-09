#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
int arr[MAX] = {0};
int dp[MAX] = {0};
int T,N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int t=1;t<=T;t++) {
		fill(arr,arr+MAX,0);
		fill(dp,dp+MAX,0);
		cin>>N>>K;
		for(int i=1;i<=N;i++) {
			cin>>arr[i];	
		}
		int len = 1;
		dp[1] = arr[1];
		for(int i=2;i<=N;i++) {
			if(dp[len] < arr[i]) {
				dp[++len] = arr[i];	
			}
			else {
				int idx = lower_bound(dp+1,dp+len+1,arr[i])-dp;
				dp[idx] = arr[i];
			}
		}
		ans = 0;
		if(K <= len) {
			ans = 1;
		}
		cout<<"Case #"<<t<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}