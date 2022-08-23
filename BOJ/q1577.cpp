#include<bits/stdc++.h>
#define MAX 101
typedef long long ll;
using namespace std;
ll dp[MAX][MAX] = {0};
int check[MAX][MAX][2] = {0};
int N,M,K,a,b,c,d;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	cin>>K;
	for(int i=0;i<K;i++) {
		cin>>a>>b>>c>>d;
		if(a > c || b > d) {
			swap(a,c);
			swap(b,d);
		}
		if(a == c) {
			check[c][d][1] = 1;
		}
		else {
			check[c][d][0] = 1;	
		}
	}
	for(int i=1;i<=N;i++) {
		if(check[i][0][0]) break;
		dp[i][0] = 1;
	}
	for(int j=1;j<=M;j++) {
		if(check[0][j][1]) break;
		dp[0][j] = 1;
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(check[i][j][0] || check[i][j][1]) {
				if(check[i][j][0] && check[i][j][1]) {	
					dp[i][j] = 0;
				}
				else {
					if(check[i][j][0]) {
						dp[i][j] = dp[i][j-1];
					}
					else {
						dp[i][j] = dp[i-1][j];	
					}
				}
			}
			else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
	}
	cout<<dp[N][M]<<"\n";
	return 0;
}