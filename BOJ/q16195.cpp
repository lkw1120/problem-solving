#include<bits/stdc++.h>
#define MAX 1001
#define DIV 1000000009
typedef long long ll;
using namespace std;
ll dp[MAX][MAX] = {0};
ll T,N,M,ans;
void preload() {
	dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = 1;
	for(int i=3;i<MAX;i++) {
		for(int j=2;j<=i;j++) {
			dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1])%DIV;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	preload();
	cin>>T;
	while(T--) {
		cin>>N>>M;
		ans = 0;
		for(int i=1;i<=M;i++) {
			ans = (ans+dp[N][i])%DIV;
		}
		cout<<ans<<"\n";
	}
	return 0;
}