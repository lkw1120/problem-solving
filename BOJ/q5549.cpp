#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dp[3][1001][1001] = {0};
int N,M,K,A,B,C,D,X,Y,Z;
void solve() {
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			dp[0][i][j] = dp[0][i-1][j]+dp[0][i][j-1]-dp[0][i-1][j-1];
			dp[1][i][j] = dp[1][i-1][j]+dp[1][i][j-1]-dp[1][i-1][j-1];
			dp[2][i][j] = dp[2][i-1][j]+dp[2][i][j-1]-dp[2][i-1][j-1];
			if(v[i-1][j-1] == 'J') dp[0][i][j]++;
			if(v[i-1][j-1] == 'O') dp[1][i][j]++;
			if(v[i-1][j-1] == 'I') dp[2][i][j]++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	cin>>K;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	solve();
	for(int i=0;i<K;i++) {
		cin>>A>>B>>C>>D;
		X = dp[0][C][D]-dp[0][A-1][D]-dp[0][C][B-1]+dp[0][A-1][B-1];
		Y = dp[1][C][D]-dp[1][A-1][D]-dp[1][C][B-1]+dp[1][A-1][B-1];
		Z = dp[2][C][D]-dp[2][A-1][D]-dp[2][C][B-1]+dp[2][A-1][B-1];
		cout<<X<<" "<<Y<<" "<<Z<<"\n";
	}
	return 0;
}