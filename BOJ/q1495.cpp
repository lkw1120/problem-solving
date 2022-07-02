#include<bits/stdc++.h>
using namespace std;
int arr[51]= {0};
bool dp[51][1001] = {false};
int N,S,M,ans;
void solve() {
	dp[0][S] = true;
	for(int i=1;i<=N;i++) {
		for(int j=0;j<=M;j++) {
			if(dp[i-1][j]) {
				if(j+arr[i] <= M) {
					dp[i][j+arr[i]] = true;	
				}
				if(j-arr[i] >= 0) {
					dp[i][j-arr[i]] = true;
				}
			}
		}
	}
	for(int i=M;i>=0;i--) {
		if(dp[N][i]) {
			ans = i;
			break;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>S>>M;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	ans = -1;
	solve();
	cout<<ans<<"\n";
	return 0;
}