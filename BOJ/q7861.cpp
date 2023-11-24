#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
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
	ans = 0;
	for(int i=1;i<=N;i++) {
		dp[i] = 1;
		for(int j=1;j<i;j++) {
			if(arr[j] < arr[i]) {
				dp[i] = max(dp[i],dp[j]+1);	
			}
		}
		ans = max(ans,dp[i]);
	}
	cout<<ans<<"\n";
	return 0;
}