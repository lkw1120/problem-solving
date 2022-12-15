#include<bits/stdc++.h>
#define MAX 1025
using namespace std;
int dp[MAX][MAX] = {0};
int N,M,K,a,b,c,d,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>dp[i][j];
			dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	cin>>K;
	while(K--) {
		cin>>a>>b>>c>>d;
		ans = dp[c][d]-dp[a-1][d]-dp[c][b-1]+dp[a-1][b-1];
		cout<<ans<<"\n";
	}
	return 0;	
}