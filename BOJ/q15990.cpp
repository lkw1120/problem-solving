#include<bits/stdc++.h>
#define MAX 100001
#define DIV 1000000009
typedef long long ll;
using namespace std;
ll dp[MAX][3] = {0};
ll T,N,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	dp[1][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	for(int i=4;i<MAX;i++) {
		dp[i][0] += (dp[i-1][1] + dp[i-1][2])%DIV;
		dp[i][1] += (dp[i-2][0] + dp[i-2][2])%DIV;
		dp[i][2] += (dp[i-3][0] + dp[i-3][1])%DIV;
	}
	for(int t=0;t<T;t++) {
		cin>>N;
		ans = (dp[N][0]+dp[N][1]+dp[N][2])%DIV;
		cout<<ans<<"\n";
	}
	return 0;
}