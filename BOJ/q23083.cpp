#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7;
ll arr[1002][1002] = {0};
ll dp[1002][1002] = {0};
ll N,M,K,X,Y,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	cin>>K;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			arr[i][j] = 1;	
		}
	}
	for(int i=0;i<K;i++) {
		cin>>X>>Y;
		arr[X][Y] = 0;
	}
	dp[1][1] = 1;
	for(int j=1;j<=M;j++) {
		for(int i=1;i<=N;i++) {
			if(arr[i][j]) {
				if(j%2) {
					dp[i][j] = (dp[i-1][j]+dp[i-1][j-1]+dp[i][j-1]+dp[i][j])%MOD;
				}
				else {
					dp[i][j] = (dp[i-1][j]+dp[i][j-1]+dp[i+1][j-1]+dp[i][j])%MOD;
				}
			}
		}
	}
	ans = dp[N][M];
	cout<<ans<<"\n";
	return 0;
}