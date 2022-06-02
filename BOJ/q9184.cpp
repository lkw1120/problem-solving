#include<bits/stdc++.h>
using namespace std;
int dp[21][21][21] = {0};
int A,B,C;
long solve(int a, int b, int c) {
	if(a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if(a > 20 || b > 20 || c > 20) {
		if(dp[20][20][20] == 0) {
			dp[20][20][20] = solve(20, 20, 20);
		}
		return dp[20][20][20];
	}
	else if(a < b && b < c) {
		if(dp[a][b][c-1] == 0) {
			dp[a][b][c-1] = solve(a, b, c-1);
		}
		if(dp[a][b-1][c-1] == 0) {
			dp[a][b-1][c-1] = solve(a, b-1, c-1);
		}
		if(dp[a][b-1][c] == 0) {
			dp[a][b-1][c] = solve(a, b-1, c);
		}
    	return dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c];
	}
	else {
		if(dp[a-1][b][c] == 0) {
			dp[a-1][b][c] = solve(a-1, b, c);
		}
		if(dp[a-1][b-1][c] == 0) {
			dp[a-1][b-1][c] = solve(a-1, b-1, c);
		}
		if(dp[a-1][b][c-1] == 0) {
			dp[a-1][b][c-1] = solve(a-1, b, c-1);
		}
		if(dp[a-1][b-1][c-1] == 0) {
			dp[a-1][b-1][c-1] = solve(a-1, b-1, c-1);
		}
    	return dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] - dp[a-1][b-1][c-1];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(true) {
		cin>>A>>B>>C;
		if(A == -1 && B == -1 && C == -1) break;
		cout<<"w("<<A<<", "<<B<<", "<<C<<") = "<<solve(A,B,C)<<"\n";
	}
	return 0;
}