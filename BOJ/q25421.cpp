#include<bits/stdc++.h>
#define MAX 100001
#define DIV 987654321
using namespace std;
int dp[10][MAX] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<10;i++) {
		dp[i][1] = 1;
	}
	for(int k=2;k<=N;k++) {
		for(int i=1;i<10;i++) {
			for(int j=1;j<10;j++) {
				if(i-2 <= j && j <= i+2) {
					dp[i][k] = (dp[i][k] + dp[j][k-1])%DIV;	
				}
			}
		}
	}
	ans = 0;
	for(int i=1;i<10;i++) {
		ans = (ans + dp[i][N])%DIV;
	}
	cout<<ans<<"\n";
	return 0;	
}