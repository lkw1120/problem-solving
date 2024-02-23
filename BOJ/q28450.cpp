#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1001;
ll arr[MAX][MAX];
ll dp[MAX][MAX];
ll N,M,H;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];	
		}
	}
	cin>>H;
	for(int i=1;i<=N;i++) {
		dp[i][1] = dp[i-1][1]+arr[i][1];
	}
	for(int j=1;j<=M;j++) {
		dp[1][j] = dp[1][j-1]+arr[1][j];
	}
	for(int i=2;i<=N;i++) {
		for(int j=2;j<=M;j++) {
				dp[i][j] = arr[i][j]+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	if(dp[N][M] <= H) {
		cout<<"YES"<<"\n";
		cout<<dp[N][M]<<"\n";
	}
	else {
		cout<<"NO"<<"\n";	
	}
	return 0;
}