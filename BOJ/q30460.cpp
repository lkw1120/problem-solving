#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;
int arr[MAX];
int dp[MAX];
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	for(int i=1;i<N+3;i++) {
		dp[i] = dp[i-1]+arr[i];
		if(3 <= i) {
			int sum = 0;
			for(int j=0;j<3;j++) {
				sum+=arr[i-j];
			}
			dp[i] = max(dp[i],dp[i-3]+2*sum);
		}
	}
	ans = dp[N+2];
	cout<<ans<<"\n";
	return 0;
}