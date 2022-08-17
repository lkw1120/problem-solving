#include<bits/stdc++.h>
#define MAX 2001
#define DIV 100999
using namespace std;
int dp[MAX][MAX] = {0};
int T,N;
void preload() {
	for(int i=0;i<MAX;i++) {
		dp[0][i] = 1;
	}
	for(int i=1;i<MAX;i++) {
		for(int j=1;j<MAX;j++) {
			dp[i][j] = dp[i][j-1];	
			if(i >= j) {
				dp[i][j] = (dp[i][j]+dp[i-j][j-1])%DIV;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	preload();
	cin>>T;
	for(int t=0;t<T;t++) {
		cin>>N;
		cout<<dp[N][N]<<"\n";
	}
	return 0;
}