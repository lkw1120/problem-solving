#include<bits/stdc++.h>
#define MAX 1002
#define DIV 1000000007
using namespace std;
int bridge[MAX][MAX] = {0};
int dp[MAX][MAX] = {0};
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>bridge[i][j];	
		}
	}
	for(int j=1;j<=M;j++) {
		dp[1][j] = bridge[1][j];
	}
	for(int i=2;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(bridge[i][j]) {
				dp[i][j] = ((dp[i-1][j-1]+dp[i-1][j])%DIV+dp[i-1][j+1])%DIV;
			}
		}
	}
	ans = 0;
	for(int j=1;j<=M;j++) {
		ans = (ans+dp[N][j])%DIV;
	}
	cout<<ans<<"\n";
	return 0;	
}