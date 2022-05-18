#include<bits/stdc++.h>
#define MAX 2001
using namespace std;
int input[MAX] = {0};
int dp[MAX][MAX] = {0};
int N,S,E,M,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>input[i];
		dp[i][i] = 1;
	}
	for(int i=1;i<N;i++) {
		if(input[i] == input[i+1]) {
			dp[i][i+1] = 1;
		}
	}
	for(int i=N-1;i>=1;i--) {
		for(int j=i+2;j<=N;j++) {
			if(dp[i+1][j-1] == 1 && input[i] == input[j]) {
				dp[i][j] = 1;
			}
		}
	}
	cin>>M;
	for(int i=0;i<M;i++) {
		cin>>S>>E;
		cout<<dp[S][E]<<"\n";	
	}
	return 0;
}