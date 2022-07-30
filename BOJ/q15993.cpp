#include<bits/stdc++.h>
#define MAX 100001
#define DIV 1000000009
using namespace std;
int dp[MAX][2] = {0};
int T,N;
void preload() {
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[3][1] = 2;
	dp[2][0] = 1;
	dp[3][0] = 2;
	for(int i=4;i<MAX;i++) {
		dp[i][1] = ((dp[i-1][0] + dp[i-2][0])%DIV + dp[i-3][0])%DIV;
		dp[i][0] = ((dp[i-1][1] + dp[i-2][1])%DIV + dp[i-3][1])%DIV;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	preload();
	cin>>T;
	while(T--) {
		cin>>N;
		cout<<dp[N][1]<<" "<<dp[N][0]<<"\n";
	}
	return 0;	
}