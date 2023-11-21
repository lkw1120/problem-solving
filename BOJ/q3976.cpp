#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int dp[MAX][2];
int arr1[MAX][2];
int arr2[MAX][2];
int T,N,L1,L2,S1,S2,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N>>L1>>L2>>S1>>S2;
		for(int i=1;i<N;i++) {
			cin>>arr1[i][0];	
		}
		for(int i=1;i<N;i++) {
			cin>>arr2[i][0];
		}
		for(int i=1;i<N;i++) {
			cin>>arr1[i][1];	
		}
		for(int i=1;i<N;i++) {
			cin>>arr2[i][1];	
		}
		dp[1][0] = L1;
		dp[1][1] = L2;
		for(int i=2;i<=N;i++) {
			dp[i][0] = min(dp[i-1][0]+arr2[i-1][0],dp[i-1][1]+arr1[i-1][1]);
			dp[i][1] = min(dp[i-1][1]+arr2[i-1][1],dp[i-1][0]+arr1[i-1][0]);
		}
		ans = min(dp[N][0]+S1,dp[N][1]+S2);
		cout<<ans<<"\n";
	}
	return 0;
}